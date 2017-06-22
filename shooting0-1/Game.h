#pragma once
#include "d3dapp.h"
#include <d3dx9math.h>
#include <D3dx9shape.h>
#include "Ground.h"

struct BULLET
{
	int nLife;
	D3DXVECTOR3 vPos;
	D3DXMATRIX matTranslation;
};

struct BULLET_PROPERTY
{
	float fBulletVelcoty;
	float fScale;		
	D3DXMATRIX matScale;	

	// Ÿ��
	D3DXVECTOR3 vMin, vMax;
};

struct PLAYER
{
	int nLife;
	D3DXVECTOR3 vPos;
	float fScale;
	float fRotationY;

	float fVelocity;
	
	// �Ѿ˿� ���� �Ӽ�	
	DWORD dwBulletFireTime;
	DWORD dwOldBulletFireTime;

	D3DXMATRIX matWorld;
	D3DXMATRIX matScale;
	D3DXMATRIX matRotationY;
	D3DXMATRIX matTranslation;		

	// ���ΰ� �浹 �ڽ�
	D3DXVECTOR3 vMin, vMax;
};


struct ENEMY
{
	int nLife;
	DWORD dwAppearTime;
	D3DXVECTOR3 vPos;

	DWORD dwOldFireTime; // �̻��� �߻� ���� �ð�
	D3DXMATRIX matTranslation;
};

struct ENEMY_PROPERTY
{
	float fMoveVelcoty;
	float fScale;

	DWORD dwFireTime; // �̻��� �߻� �ð� ����
	D3DXMATRIX matScale;

	D3DXVECTOR3 vMin, vMax; // �� �̻��� �浹 �ڽ�
};

class CGame : public CD3DApp
{
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;

	CGround m_Ground;

	LPD3DXMESH m_pTeapotMesh; // ���ΰ�	
	LPD3DXMESH m_pPlayerBulletMesh; // ���ΰ� �̻��� (�����)
	LPD3DXMESH m_pEnemyBoxMesh;
	LPD3DXMESH m_pEnemyBulletMesh;

	// ���ΰ� 
	PLAYER m_sPlayer;
	BULLET_PROPERTY m_sPlayerBulletProperty;
	BULLET m_sPlayerBullet[10];

	// �� ĳ���� 
	ENEMY_PROPERTY m_EnemyProperty;
	ENEMY m_Enemy[100];   //�� ĳ���� 100�� 
	BULLET_PROPERTY m_EnemyBulletProperty;
	BULLET m_EnemyBullet[100];
	int m_nEnemyIndex;

	DWORD m_dwElapsedTime;

	// �������� ����
	DWORD m_dwGameStartTime;
	DWORD m_dwGameElapsedTime;

	// int m_nEnemyCount;
	BOOL CheckCubeIntersection(D3DXVECTOR3* vMin1, D3DXVECTOR3* vMax1, D3DXVECTOR3* vMin2, D3DXVECTOR3* vMax2);
public:
	CGame(void);
	~CGame(void);
};


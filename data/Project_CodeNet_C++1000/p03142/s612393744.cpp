//#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

/*-----------------------------------------------------------------------------
　ライブラリ
 -------------------------------------------------------------------------------*/
#if 0
// 3次元
vector<vector<vector<SDWORD>>> XXX(AAA, vector<vector<SDWORD>>(BBBB, vector<SDWORD>(CCC, -1)));
#endif

#if 0
// 2分探索
auto position = lower_bound(getValue.begin(), getValue.end(), 0);	// 0以上の要素位置を探す
int idx_lower = distance(getValue.begin(), position);				// 0以上の要素インデックス
int eraseNum = MIN(idx_lower, delCnt);								// 要素位置が個数になる
#endif

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define MIN(a, b)				((a) < (b) ? a : b)
#define MAX(a, b)				((a) > (b) ? a : b)
#define CeilN(x, n)				(((((DWORD)(x))+((n)-1))/n)*n)	/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))					/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						

#define ArrayLength(x)			( sizeof( x ) / sizeof( x[ 0 ] ) )
#define	ArrayEnd(a)				(&(a)[ArrayLength(a)])			
#define	ArrayLast(a)			(&(a)[ArrayLength(a) - 1])		
#define MAX_DWORD				(0xFFFFFFFF)
#define	MAX_SDWORD				((SDWORD)0x7FFFFFFF)
#define	MIN_SDWORD				((SDWORD)0x80000000)
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define	MIN_QWORD				((QWORD)0x0000000000000000)
#define	MAX_SQWORD				((SQWORD)0x7FFFFFFFFFFFFFFF)
#define	MIN_SQWORD				((SQWORD)0x8000000000000000)
#define M_PI					3.14159265358979
#define deg_to_rad(deg)			(((deg)/360)*2*M_PI)
#define rad_to_deg(rad)			(((rad)/2/M_PI)*360)

#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
typedef short					SWORD;
typedef long					SDWORD;
typedef long long				SQWORD;
typedef unsigned short			WORD;
typedef unsigned long			DWORD;
typedef unsigned long long int	QWORD;
typedef pair<int, int> P;

/*-----------------------------------------------------------------------------
　パラメータ定義
 -------------------------------------------------------------------------------*/
#define N_MAX	(100000)
#define K_MAX	(10)
#define M_MAX	(1000)
#define H_MAX	(1000)
#define W_MAX	(1000)
/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
// メイン
int main()
{
	int N, M;
	static vector<int> G[N_MAX + 1];
	static int jigen[N_MAX + 1];

	// 入力
	cin >> N >> M;
	REP(i, N + M - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		jigen[b]++;
	}

	// 親探し
	int root = 0;
	REP(i, N + M - 1) {
		if (jigen[i] == 0) {
			root = i;
			break;
		}
	}

	// トポロジカルソート
	queue<int> que;
	static int parentList[N_MAX + 1];
	que.push(root);
	parentList[root] = 0;
	while (!que.empty()) {
		int parent = que.front();
		que.pop();

		for (auto gOne : G[parent]) {
			jigen[gOne]--;
			if (jigen[gOne] == 0) {
				que.push(gOne);
				parentList[gOne] = parent + 1;
			}
		}

	}
	
	// リスト表示
	REP(i, N) {
		cout << parentList[i] << endl;
	}
	cout << endl;
	return 0;
}

//#include "stdafx.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <assert.h>
#include <functional>
#include <unordered_map>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
template<class T>
class UnionFind
{
private:
	vector<T> parentNo;
	vector<T> parentRank;
	vector<T> parentSize;

public:
	// コンストラクタ
	UnionFind(int n) 
	{
		parentNo.resize(n);
		parentRank.resize(n, 0);
		parentSize.resize(n, 1);
		for (int i = 0; i < n; i++) {
			// 始めは全部ROOT
			parentNo[i] = i;
		}
	}

	int root(T x) 
	{
		if (parentNo[x] == x) {
			return x;
		} else {
			T rootParentNo = root(parentNo[x]);
			parentNo[x] = rootParentNo;
			return rootParentNo;
		}
	}

	bool same(T x, T y) 
	{
		return root(x) == root(y);
	}

	int size(T x) 
	{
		return parentSize[root(x)];
	}

	void unite(T xc, T yc) 
	{
		T xr = root(xc);
		T yr = root(yc);
		if (xr == yr) {
			return;
		}
		if (parentRank[xr] < parentRank[yr]) {
			parentNo[xr] = yr;
			parentSize[yr] += parentSize[xr];
		} else {
			parentNo[yr] = xr;
			parentSize[xr] += parentSize[yr];
			if (parentRank[xr] == parentRank[yr]) {
				parentRank[xr]++;
			}
		}
	}
};


int main()
{
	vector<int> p;
	int N, M;

	cin >> N >> M;
	REP(i, N) {
		int a;
		cin >> a;
		a--;
		p.emplace_back(a);
	}

	UnionFind<int> uTree(N + 1);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		uTree.unite(a, b);
	}

	int ans = 0;
	REP(i, N) {
		if (uTree.same(i, p[i])) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}

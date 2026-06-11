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
// 枝定義
struct Edge
{
	int	toIdx;
	int	revIdx;
	int	cap;
	Edge(){}
	Edge(int to, int rev, int capArg): toIdx(to), revIdx(rev), cap(capArg){}
};

// グラフ定義(二次元配列)
using Graph = vector<vector<Edge>>;
 
// フォード・ファルカーソン
class FordFulkerson 
{
private:
	int V;
	Graph G;
	vector<bool> isUsed;

private:
	int dfs(int from, int sinkPos, int flow)
	{
		if (from == sinkPos) {
			return flow;
		}

		int flowOne = 0;
		isUsed[from] = true;
		for (Edge &edge : G[from]) {
			int to = edge.toIdx;
			if (!isUsed[to]) {
				if (0 < edge.cap) {
					flowOne = dfs(to, sinkPos, min(flow, edge.cap));
					if (0 < flowOne) {
						edge.cap -= flowOne;
						G[to][edge.revIdx].cap += flowOne;
						break;
					}
				}
			}
		}
		return flowOne;
	}

public:
	FordFulkerson(int N)
	{
		G.resize(N);
	}

	// 枝を追加
	void AddEdge(int from, int to, int cap)
	{
		int revIdxTo = G[to].size();
		int revIdxFrom = G[from].size();
		G[from].emplace_back(to, revIdxTo, cap);
		G[to].emplace_back(from, revIdxFrom, 0);
	}

	// 最大フローを求める
	int GetMaxFlow(int startPos, int endPos)
	{
		int maxFlow = 0;
		V = (int)G.size();
		isUsed.resize(V);
		for (;;) {
			fill(isUsed.begin(), isUsed.end(), false);
			int flowOne = dfs(startPos, endPos, (int)INF);
			if (flowOne == 0) {
				break;
			}
			maxFlow += flowOne;
		}
		return maxFlow;
	}
};


int main()
{
	int N;
	cin >> N;
	vector<P> red, blue;
	REP(i, N) {
		int a, b;
		cin >> a >> b;
		red.emplace_back(a, b);
	}
	REP(i, N) {
		int a, b;
		cin >> a >> b;
		blue.emplace_back(a, b);
	}
	
	FordFulkerson res(2 * N + 2);
	
	// 赤→青
	REP(i, N) {
		REP(j, N) {
			auto redOne = red[i];
			auto blueOne = blue[j];
			if ((redOne.first < blueOne.first) && (redOne.second < blueOne.second)) {
				res.AddEdge(i, j + N, 1);
			}
		}
	}

	// 始点→赤
	int start = 2 * N;
	REP(i, N) {
		res.AddEdge(start, i, 1);
	}
	
	// 青→終点
	int end = 2 * N + 1;
	REP(i, N) {
		res.AddEdge(i + N, end, 1);
	}
	
	// 最大流量
	int ans = res.GetMaxFlow(start, end);
	cout << ans << endl;
	return 0;
}

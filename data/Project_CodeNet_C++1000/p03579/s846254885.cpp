#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (int)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>        P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
// 枝定義
struct Edge
{
	int	to;
	ll	dist;
	Edge(){}
	Edge(int to, ll dist) : to(to), dist(dist){}
};

template <class E>
using Graph = vector<vector<E>>;

// dfs
Graph<Edge>		G;
vector<int>		color;
bool dfs(int from, int fromCol)
{
	color[from] = fromCol;
	for (auto next : G[from]) {
		if (color[next.to] == 0) {
			if (!dfs(next.to, fromCol * (-1))) {
				return false;
			}
		} else if (color[next.to] == fromCol) {
			return false;
		} else {
			// すでに塗ってる
		}
	}

	return true;
}

// メイン
int main()
{
	ll N, M;
	cin >> N >> M;
	G.resize(N);
	color.resize(N, 0);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].emplace_back(Edge(b, 1));
		G[b].emplace_back(Edge(a, 1));
	}

	ll ans;
	if (dfs(0, 1)) {
		ll white = 0;
		ll block = 0;
		REP(i, N) {
			if (color[i] == 1) {
				white++;
			} else {
				block++;
			}
		}
		ans = white * block - M;
	} else {
		ans = N * (N - 1) / 2 - M;
	}

	cout << ans << endl;
	return 0;
}

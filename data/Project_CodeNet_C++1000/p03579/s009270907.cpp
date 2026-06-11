
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

typedef vector<vector<int>> G;
G graph;

int color[100050];

//二部グラフ判定
bool dfs(int u, int c) {
	//色ぬって
	color[u] = c;

	//隣接した頂点へ遷移
	for (int i = 0; i < graph[u].size(); i++) {

		//隣接した頂点を取得
		int v = graph[u][i];

		//色が塗ってあって、しかも同じいろなら二部グラフでない
		if (color[v] == c) {
			return false;
		}

		//色が塗ってないなら、色を反転して遷移
		if (color[v] == 0 && !dfs(v, -c)) {
			return false;
		}
	}

	//全部の頂点巡れたら二部グラフ
	return true;
}

int main() {

	LL n, m; cin >> n >> m;
	graph = G(n);

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	LL B = 0, W = 0;
	if (dfs(0, 1)) {
		for (int i = 0; i < n; i++) {
			if (color[i] == 1) {
				B++;
			}
			else if (color[i] == -1) {
				W++;
			}
		}
		//任意の白から黒に辺が張られる
		cout << B * W - m << endl;
	}
	else {
		//最後が完全グラフになる。
		//もともとm本あって、完全グラフにするには
		cout << ((n*(n - 1) / 2)) - m << endl;
	}

	return 0;
}
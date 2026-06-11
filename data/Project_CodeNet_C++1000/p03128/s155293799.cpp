#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const int INF_INT = 1 << 25;
const long long MOD = 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
const int loose = 0;
const int tight = 1;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}


void solve() {
	ll n, m;
	cin >> n >> m;
	Array a(m);
	REP(i, m) cin >> a[i];
	sort(all(a),greater<ll>());
	ll ma[10] = { -1,2,5,5,4,5,6,3,7,6 };//作るために使う本数

	Matrix dp(n + 1, Array(m, -1));//i本のマッチを使って作れる最大の桁数
	REP(i,m) dp[0][i] = 0;

	REP(i, n) {
		REP(j, m) {
			REP(k, m) {
				if (dp[i][j] != -1 && i + ma[a[k]] <= n)
					chmax(dp[i + ma[a[k]]][k], dp[i][j] + 1);
			}
		}
	}

	//桁数が一番大きいものから復元
	ll max = 0;//最大の桁数
	ll max_i = 0;
	REP(i, m) chmax(max, dp[n][i]);

	ll con = n;//マッチの本数
	while (con) {
		REP(i, m) {
			if (dp[con][i] == max) {
				max_i = i;
				break;
			}
		}

		cout << a[max_i];
		con -= ma[a[max_i]];
		max--;
	}

	cout << en;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
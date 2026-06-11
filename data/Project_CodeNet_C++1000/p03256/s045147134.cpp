//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb(a) push_back
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")

template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200020;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;


int flag[200020];
//vector<int>G[200020];
vector<int>G2[500050];
vector<P>edges;
bool possible;

bool vis[500050], act[500050];

void dfs(int n) {
	if (possible)return;
	if (vis[n])return;
	if (act[n]) { possible = true; return; }
	act[n] = true;
	for (auto nxt : G2[n]) {
		dfs(nxt);
	}
	vis[n] = true;
}

void solve() {
	int N, M; cin >> N >> M;
	string S; cin >> S;
	REP(i, N) {
		int f = S[i] - 'A';
		flag[i] = f;
	}
	REP(i, M) {
		int u, v; cin >> u >> v;
		u--, v--;
		if (!flag[u]) {
			if (!flag[v]) {
				G2[u].push_back(v+N);
				G2[v].push_back(u+N);
			}
			else {
				G2[u + N].push_back(v);
				G2[v + N].push_back(u);
			}
		}
		else {
			if (!flag[v]) {
				G2[u + N].push_back(v);
				G2[v + N].push_back(u);
			}
			else {
				G2[u].push_back(v + N);
				G2[v].push_back(u + N);
			}
		}
	}
	REP(i, N * 2) {
		dfs(i);
	}
	if (possible)print("Yes");
	else print("No");
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();
}
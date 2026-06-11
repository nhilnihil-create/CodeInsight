#include"bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<< #str << " " str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7


ll N, M;
vector<vector<ll>> G;
vector<ll> color;

bool dfs(ll v, ll c) {
	color[v] = c;
	for (auto p : G[v]) {
		if (color[p] == c)return false;
		if (color[p] == 0 && !dfs(p, -c))return false;
	}
	return true;
}

int main()
{
	cin >> N >> M;
	G.resize(N);
	color.resize(N, 0);
	REP(i, M) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	if (dfs(0, 1)) {
		ll res = 0;
		for (auto c : color)if (c == 1)res++;
		cout << res * (N - res) - M << endl;
		//cerr << "2th" << endl;
	}
	else {
		cout << N * (N - 1)/2 - M << endl;
		//cerr << "all" << endl;
	}

	return 0;
}

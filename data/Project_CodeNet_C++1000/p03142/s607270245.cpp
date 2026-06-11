#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	vector<vector<ll>> G(N);
	vector<ll> deg(N, 0);
	REP(i, N-1+M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		++deg[b];
	}

	queue<ll> que;
	REP(i, N) if (!deg[i]) que.push(i);

	vector<ll> par(N, 0);
	while (que.size())
	{
		ll v = que.front();
		que.pop();
		for (auto &nv : G[v])
		{
			--deg[nv];
			if (!deg[nv])
			{
				par[nv] = v + 1;
				que.push(nv);
			}
		}
	}

	for (ll i = 0; i < N; ++i)
		std::cout << par[i] << std::endl;
}

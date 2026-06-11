#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<vector<ll>> G;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	G.resize(N);

	REP(i, N-1)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<ll> C(N); REP(i, N) cin >> C[i];
	sort(ALL(C), greater<ll>());

	queue<ll> que;
	vector<ll> res(N, -1);
	que.push(0);
	res[0] = C[0];
	ll i{1};

	while (!que.empty())
	{
		ll now = que.front(); que.pop();
		for (auto &nv : G[now])
		{
			if (res[nv] != -1) continue;
			que.push(nv);
			res[nv] = C[i];
			++i;
		}
	}

	std::cout << accumulate(next(C.begin()), C.end(), 0ll)<< std::endl;
	REP(i, N)
		std::cout << (i?" ":"") << res[i];
	std::cout << std::endl;

}

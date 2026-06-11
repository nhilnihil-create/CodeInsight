#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

struct UnionFind
{
	vector<ll> par;

	void init(ll n) {par.assign(n, -1);}

	ll root(ll x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool unit(ll x, ll y)
	{
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	ll size(ll x)
	{
		return -par[root(x)];
	}
};

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	vector<ll> P(N); REP(i, N) cin >> P[i], --P[i];
	UnionFind uf;
	uf.init(N);

	REP(i, M)
	{
		ll x, y; cin >> x >> y;
		--x, --y;
		uf.unit(x, y);
	}

	ll res{0};

	REP(i, N)
	{
		if (uf.root(i) == uf.root(P[i]))
			++res;
	}

	std::cout << res << std::endl;
}

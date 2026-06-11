#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

struct UnionFind
{
	vector<ll> par;

	UnionFind(ll N = 20001) : par(N)
	{
		for (ll i = 0; i < N; ++i) par[i] = i;
	}

	ll root(ll x)
	{
		if (par[x] == x) return x;
		else return par[x] = root(par[x]);
	}

	void unite(ll x, ll y)
	{
		ll rx = root(x);
		ll ry = root(y);
		if (rx == ry) return;
		else par[rx] = ry;
	}

	bool same(ll x, ll y)
	{
		return root(x) == root(y);
	}
};

int main(int argc, char **argv)
{
	ll n, m; cin >> n >> m;
	vector<ll> p(n);
	for (ll i = 0; i < n; ++i) cin >> p[i], --p[i];

	UnionFind tree(n);
	
	for (ll i = 0; i < m; ++i)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		tree.unite(a, b);
	}

	ll cnt{0};
	for (ll i = 0; i < n; ++i)
	{
		if (tree.same(i, p[i]))
			++cnt;
	}
	std::cout << cnt << std::endl;
}
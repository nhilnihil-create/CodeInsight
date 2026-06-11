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

struct UnionFind
{
	vector<long long> par;

	void init(long long n) {par.assign(n, -1);}

	long long root(long long x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool merge(long long x, long long y)
	{
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	bool issame(long long x, long long y)
	{
		return root(x) == root(y);
	}

	long long size(long long x)
	{
		return -par[root(x)];
	}
};


ll N, M;

int main(int argc, char **argv)
{
	cin >> N >> M;

	UnionFind uf;
	uf.init(N);
	
	REP(i, M)
	{
		ll a, b, _; cin >> a >> b >> _;
		--a, --b;
		uf.merge(a, b);
	}

	ll res{1};
	REP(i, N)
	{
		if (!uf.issame(0, i))
		{
			uf.merge(0, i);
			++res;
		}
	}

	std::cout << res << std::endl;
}

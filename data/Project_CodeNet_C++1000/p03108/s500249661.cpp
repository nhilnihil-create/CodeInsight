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
vector<ll> A, B;

int main(int argc, char **argv)
{
	cin >> N >> M;
	A.resize(M);
	B.resize(M);
	UnionFind uf;
	uf.init(N);

	REP(i, M)
	{
		cin >> A[i] >> B[i];
		--A[i], --B[i];
	}

	vector<ll> res;
	ll can{N*(N-1)/2};
	for (ll i = M-1; i >= 0; --i)
	{
		res.push_back(can);
		if (uf.issame(A[i], B[i])) continue;
		
		can -= uf.size(A[i]) * uf.size(B[i]);
		uf.merge(A[i], B[i]);
	}

	reverse(ALL(res));
	for (auto &e : res)
		std::cout << e << std::endl;
}

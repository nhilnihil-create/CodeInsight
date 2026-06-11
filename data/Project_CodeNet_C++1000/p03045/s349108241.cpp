#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecb vector<bool>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}
void comb(vector<vector<long long int>> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (size_t k = 1; k < v.size(); k++)
	{
		for (size_t j = 1; j < k; j++)
		{
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}
ll repeat_squaring(ll n, ll p, ll m)
{
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		ll t = repeat_squaring(n, p / 2, m);
		return t * t % m;
	}
	return n * repeat_squaring(n, p - 1, m);
}

class UnionFind
{
public:
	vector<int> par;
	vector<int> rank;
	UnionFind(int N) : par(N)
	{
		par.resize(N);
		par.shrink_to_fit();
		rank.resize(N);
		rank.shrink_to_fit();
		for (int i = 0; i < N; i++)
			par[i] = i, rank[i] = 0;
	}
	int root(int x)
	{
		if (par[x] == x)
			return x;
		return par[x] = root(par[x]);
	}
	void merge(int x, int y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return;
		if (rank[x] < rank[y])
			swap(x, y);
		if (rank[x] == rank[y])
			++rank[x];
		par[y] = x;
		return;
	}
	bool is_same(int x, int y)
	{
		return root(x) == root(y);
	}
	size_t size()
	{
		set<int> s;
		for (size_t i = 0; i < par.size(); i++)
		{
			s.insert(root(i));
		}
		return s.size();
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	rep(i, m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		--x;
		--y;
		uf.merge(x, y);
	}
	cout << uf.size() << endl;
	return 0;
}
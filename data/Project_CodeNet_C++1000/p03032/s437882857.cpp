#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	vector<int> q(n);
	rep(i, n)cin >> q[i];
	int res = 0;
	for (int i = 0; i <= min(n, k); ++i)
	{
		int r = min(n, k) - i;
		vector<int> minus;
		int tmp = 0;
		for (int j = 1; j <= i; ++j)
		{
			tmp += q[j - 1];
			if (q[j - 1] < 0)minus.push_back(q[j - 1]);
		}
		for (int j = 0; j <= r; ++j)
		{
			int tmp2 = tmp;
			vector<int> minus2 = minus;
			for (int l = 1; l <= j; ++l)
			{
				tmp2 += q[n - l];
				if (q[n - l] < 0)minus2.push_back(q[n - l]);
			}
			sort(all(minus2));
			for (int l = 0; l < min(k - i - j, (int)minus2.size()); ++l)tmp2 -= minus2[l];
			chmax(res, tmp2);
		}
	}
	cout << res << endl;
}
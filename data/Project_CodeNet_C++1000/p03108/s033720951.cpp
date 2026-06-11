#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

struct UnionFind
{
	vector<int> uni;

	UnionFind(int n) : uni(n, -1) {}
	int root(int a)
	{
		if (uni[a] < 0) return a;
		return uni[a] = root(uni[a]);
	}

	bool connect(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b) return false;
		if (uni[a] > uni[b])
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
		uni[a] = uni[a] + uni[b];
		uni[b] = a;
		return true;
	}

	bool isConnect(int a, int b)
	{
		return root(a) == root(b);
	}

	int size(int a)
	{
		return -uni[root(a)];
	}
};

signed main(void)
{
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m), b(m), out;
	UnionFind uf(n);
	ll ans;

	rep(i, m) 
	{
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	ans = n * (n - 1) / 2;
	for (int i = m - 1; i >= 0; i--)
	{
		out.push_back(ans);
		if (!uf.isConnect(a[i], b[i]))
		{
			ans -= (ll) uf.size(a[i]) * uf.size(b[i]);  
			uf.connect(a[i], b[i]); 
		}
	}
	reverse(out.begin(), out.end());
	rep(i, m)
		cout << out[i] << endl;
	return 0;
}

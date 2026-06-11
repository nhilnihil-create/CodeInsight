#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N = 1e5 + 5;

	int Siz[N], Id[N];
	ll D[N];
	unordered_map<ll, int> M;
	vector<int> E[N];

	template <typename T>
	inline T read()
	{
		T x = 0;
		int f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	ll dfs(const int u, const int d)
	{
		ll ans = d;
		for (int v : E[u])
			ans += dfs(v, d + 1);
		return ans;
	}

	void work()
	{
		int n = read<int>();
		for (int i = 1; i <= n; i++)
		{
			ll d = D[i] = read<ll>();
			Id[i] = i;
			M[d] = i;
			Siz[i] = 1;
		}
		sort(Id + 1, Id + 1 + n, [](const int a, const int b) { return D[a] < D[b]; });
		for (int i = n; i > 1; i--)
		{
			int v = Id[i];
			ll d = D[v] + 2 * Siz[v] - n;
			if (d >= D[v] || !M.count(d))
				return void(puts("-1"));
			int u = M[d];
			Siz[u] += Siz[v];
			E[u].push_back(v);
		}
		if (dfs(Id[1], 0) != D[Id[1]])
			puts("-1");
		else
			for (int i = 1; i <= n; i++)
				for (int j : E[i])
					printf("%d %d\n", i, j);
	}
}

int main()
{
	TYC::work();
	return 0;
}
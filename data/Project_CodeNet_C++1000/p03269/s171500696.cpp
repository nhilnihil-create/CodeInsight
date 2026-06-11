#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int l;
	cin >> l;
	int n = log2(l);
	l--;
	vector<pair<int, int>> g[n + 1];
	int es = 2 * n;
	for (int i = 0; i < n; i++)
	{
		g[i].push_back(make_pair(i + 1, 0));
		g[i].push_back(make_pair(i + 1, 1 << i));
	}
	int x = l, m = n, s = 0;
	while (m)
	{
		int y = x - (1 << m);
		if (y == -1)
			break;
		int k = log2(y + 1);
		s += 1 << m;
		g[k].push_back(make_pair(n, s));
		x = y;
		m = k;
		es++;
	}
	cout << n + 1 << ' ' << es << endl;
	for (int i = 0; i <= n; i++)
	{
		for (auto &p : g[i])
		{
			cout << i + 1 << ' ' << p.first + 1 << ' ' << p.second << '\n';
		}
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

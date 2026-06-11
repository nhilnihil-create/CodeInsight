#include "bits/stdc++.h"

using namespace std;

void fail()
{
	cout << -1 << endl;
	exit(0);
}

void solve(void)
{
	int n;
	string s;
	cin >> s;
	n = s.size();
	if (s.back() == '1' || s.front() == '0')
	{
		fail();
	}
	vector<int> vs;
	for (int i = 2; i <= n / 2; i++)
	{
		if (s[i-1] != s[n-i-1])
		{
			fail();
		}
		if (s[i-1] == '1')
		{
			vs.push_back(i);
		}
	}
	vector<int> g[n];
	int now = 1, pr = n-1, pv = 1;
	for (int v : vs)
	{
		int r = now++;
		g[pr].push_back(r);
		for (int i = 0; i < v - 1 - pv; i++)
		{
			g[r].push_back(now++);
		}
		pr = r;
		pv = v;
	}
	g[0].push_back(pr);
	for (int i = now; i < n-1; i++)
	{
		g[0].push_back(now++);
	}
	for (int i = 0; i < n; i++)
	{
		for (int v : g[i])
		{
			cout << i + 1 << ' ' << v + 1 << '\n';
		}
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

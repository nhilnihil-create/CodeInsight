#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	cin >> n;
	string s;
	map<string, int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (q.count(s) == 0)
			q[s] = 1;
		else
			q[s] += 1;
	}
	cin >> m;
	string t;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		if (q.count(t) == 0)
			q[t] = -1;
		else
			q[t] -= 1;
	}
	int mx = 0;
	map<string, int>::iterator it;
	for (it = q.begin(); it != q.end(); it++)
	{
		mx = max(mx, it->second);
	}
	cout << mx << endl;
}


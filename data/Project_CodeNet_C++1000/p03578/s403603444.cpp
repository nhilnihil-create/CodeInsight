#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	int m;
	cin >> m;
	vector<int> t(m);
	for (int i = 0; i < m; i++)
	{
		cin >> t[i];
	}
	map<int, int> a;
	for (int x : d)
	{
		a[x]++;
	}
	bool ans = true;
	for (int x : t)
	{
		if (a[x] == 0)
		{
			ans = false;
			break;
		}
		else
		{
			a[x]--;
		}
	}
	if (ans == true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
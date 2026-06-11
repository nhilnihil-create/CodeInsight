#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	string s, t, u;
	cin >> n;
	cout << 0 << endl;
	cin >> s; 
	cout << n - 1 << endl;
	cin >> t;
	if (s == "Vacant" || t == "Vacant") return 0;

	int l, r, m;
	l = 0;
	r = n - 1;
	while(true)
	{
		m = (l + r) / 2;
		cout << m << endl;
		cin >> u;
		if (u == "Vacant") return 0;
		if ((m  - l) % 2 == 0)
		{
			if (u != s)
			{
				r = m;
				t = u;
			}
			else
			{
				l = m;
				s = u;
			}
		}
		else
		{
			if (u == s)
			{
				r = m;
				t = u;
			}
			else
			{
				l = m;
				s = u;
			}
		}
	}
}

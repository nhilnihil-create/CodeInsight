#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n; 
	long long a, b, c, cnt;
	string s[n];

	rep(i, n) cin >> s[i];
	a = b = c = cnt = 0;
	rep(i, n)
	{
		rep(j, s[i].size() - 1)
		{
			if (s[i].substr(j, 2) == "AB")
				cnt++;
		}
		if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')
			c++;
		else if (s[i][s[i].size() - 1] == 'A')
			a++;
		else if (s[i][0] == 'B')
			b++;
	}
	if (c == 0)
		cnt += min(a, b);
	else if (a + b > 0)
		cnt += c + min(a, b); 
	else
		cnt += c - 1;
	cout << cnt << endl;
	return 0;
}

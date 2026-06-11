#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	long long ans, cnt;
	cin >> s;
	rep(i, s.size() - 1)
	{
		if (s.substr(i, 2) == "BC")
		{
			t += 'D';
			i++;
		}
		else
			t += s[i]; 
	}
	ans = cnt = 0;
	for(int i = t.size(); i >= 0; i--)
	{
		if (t[i] == 'A') 
			ans += cnt;
		else if (t[i] == 'D')
			cnt++;
		else
			cnt = 0;
	}
	cout << ans << endl;
	return 0;
}

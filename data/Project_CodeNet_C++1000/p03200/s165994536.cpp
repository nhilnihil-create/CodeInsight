#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	string s;
	cin >> s;
	ull cnt_b = 0, i, ans = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == 'B')
			cnt_b++;
		else
			ans += cnt_b;
	}
	cout << ans;
	return 0;
}
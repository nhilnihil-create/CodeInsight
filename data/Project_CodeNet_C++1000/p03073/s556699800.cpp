#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
int main()
{
	alphanso;
	string s;
	cin >> s;
	int i, flag = 0;
	for (i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			(s[i] == '1') ? s[i] = '0' : s[i] = '1';
			flag++;
		}
	}
	cout << flag;
	return 0;
}
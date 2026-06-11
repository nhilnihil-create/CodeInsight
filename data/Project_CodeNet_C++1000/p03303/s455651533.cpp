#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(void)
{
	string s;
	int w, cnt;

	cin >> s >> w;
	cnt = w;
	rep(i, s.size())
	{
		if (cnt == w)
		{
			cout << s[i];
			cnt = 0;
		}
		cnt++;
	}
	return 0;
}

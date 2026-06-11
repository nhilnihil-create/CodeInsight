#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	for (int i = 0; i < 8; ++i)
	{
		int ans = s[0]-48;
		string op = "";
		for (int j = 2; j >= 0; --j)
		{
			if (i & 1 << j)
			{
				ans -= s[3-j]-48;
				op += "-";
			}
			else
			{
				ans += s[3-j]-48;
				op += "+";
			}
		}
		if (ans == 7)
		{
			op += "=";
			for (int i = 0; i < 4; ++i)
				cout << s[i] << op[i];
			cout << 7 << endl;
			return 0;
		}
	}
}


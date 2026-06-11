#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> v(4);
	vector<char> op(3);
	for (int i = 0; i < 4; i++)
	{
		v[i] = s[i] - '0';
	}

	int ans = 0;
	for (int bit = 0; bit < (1 << 3); bit++)
	{
		int ans = v[0];
		for (int i = 0; i < 3; i++)
		{
			if (bit & (1 << i))
			{
				ans += v[i + 1];
				op[i] = '+';
			}
			else
			{
				ans -= v[i + 1];
				op[i] = '-';
			}
		}
		if (ans == 7)
		{
			cout << v[0];
			for (int i = 0; i < 3; i++)
			{
				cout << op[i] << v[i + 1];
			}
			cout << "=7" << '\n';
			return 0;
		}
	}
	return 0;
}

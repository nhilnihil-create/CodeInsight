#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		string t = s.substr(0, i), u = s.substr(i, n);

		set<char> ts, us;
		for (auto &&c : t)
		{
			ts.insert(c);
		}
		for (auto &&c : u)
		{
			us.insert(c);
		}

		int tmp = 0;

		for (auto &&c : ts)
		{
			if (us.find(c) != us.end())
			{
				tmp++;
			}
		}

		ans = max(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}
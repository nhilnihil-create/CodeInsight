#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int ans = 0;
	for (int i = a; i <= b; i++)
	{
		string s = to_string(i);
		string t(s);
		reverse(t.begin(), t.end());

		int x = stoi(s);
		int y = stoi(t);

		if (x == y)
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
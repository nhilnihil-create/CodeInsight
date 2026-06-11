#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a == b)
			cout << 2 * (a - 1) << endl;
		else if (a + 1 == b)
			cout << 2 * (a - 1) << endl;
		else
		{
			ll c = sqrt(a * b);
			if (c * c == a * b)
				--c;
			if (c * (c + 1) < a * b)
				cout << 2 * c - 1 << endl;
			else
				cout << 2 * c - 2 << endl;
		}
	}
	return 0;
}

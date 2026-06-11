#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int		main(void)
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	X *= 2; Y *= 2;
	int x = 0, y = 0;
	ll ans = 0;
	if (C*2 <= A+B)
	{
		while (x < X && y < Y)
		{
			ans += (ll)C;
			x++;
			y++;
		}
	}
	if (C*2 <= A)
	{
		while (x < X)
		{
			ans += (ll)C;
			x++;
		}
	}
	else
	{
		while (x < X)
		{
			ans += (ll)A;
			x += 2;
		}
	}
	if (C*2 <= B)
	{
		while (y < Y)
		{
			ans += (ll)C;
			y++;
		}
	}
	else
	{
		while (y < Y)
		{
			ans += (ll)B;
			y += 2;
		}
	}
	cout << ans << endl;
}


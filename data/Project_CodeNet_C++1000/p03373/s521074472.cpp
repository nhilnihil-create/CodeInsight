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
	ll ans = 1e18;
	for (int i = 0; i <= max(X, Y); i++)
	{
		ll price = C * 2 * i;
		if (i < X)
			price += (X-i) * A;
		if (i < Y)
			price += (Y-i) * B;
		ans = min(ans, price);
	}
	cout << ans << endl;
}


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll ans;
	if (k % 2)
		ans = b - a;
	else
		ans = a - b;
	if (ans > 1000000000000000000)
		cout << "Unfair" << endl;
	else
		cout << ans << endl;
}

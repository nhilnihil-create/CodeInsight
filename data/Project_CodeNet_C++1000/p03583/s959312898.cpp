#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	ll N;
	cin >> N;
	for (ll h = 1; h <= 3500; h++) 
	{
		for (ll w = 1; w <= 3500; w++)
		{
			ll n = N * w * h;
			ll m = 4 * w * h - N * h - N * w;
			if (m <= 0 || n % m != 0) continue;
			n /= m;
			cout << h << " " << w << " " << n << endl; 
			return 0;
		}
	}
	return 0;
}

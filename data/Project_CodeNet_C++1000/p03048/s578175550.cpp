#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

int main() {
	vector<ll> num(3);
	ll n, ans = 0;
	cin >> num[0] >> num[1] >> num[2] >> n;
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			if ((n - i * num[0] - j * num[1]) >= 0 && (n - i * num[0] - j * num[1]) % num[2] == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
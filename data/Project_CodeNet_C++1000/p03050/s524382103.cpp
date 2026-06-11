#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	for (ll i = 1; i*i <= n; i++)
	{
		if ((n-i)%i == 0 && i < (n-i)/i) sum += (n-i) / i;
	}
	cout << sum << endl;

	return 0;
}
#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll a, b, k,c;
	ll ans = 0;
	cin >> k >> a >> b;
	if (b - a <= 2) {
		cout << 1 + k << endl; return 0;}
	else {
		c = max(0LL, ll(floor((k - (a - 1LL)) / 2LL)));
		ans = (b - a) * c;
		if ((k - (a - 1)) % 2 == 1)ans++;
	}
	cout << a + ans << endl;
	return 0;
}


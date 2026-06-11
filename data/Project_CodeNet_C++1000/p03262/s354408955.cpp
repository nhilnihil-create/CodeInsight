#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep (i, n) {
		cin >> a[i]; 
		a[i] = abs(a[i] - x);
	}
	int ans = 0;
	rep(i, n) {
		ans = gcd(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i] -= (i + 1);
	sort(a.begin(), a.end());
	if (n % 2 == 1) {
		ll d = a[n / 2];
		ll ans = 0;
		rep(i, n) ans += abs(a[i] - d);
		cout << ans << endl;
	}
	else {
		ll d = (a[n / 2] + a[n / 2 - 1]) / 2;
		ll ans = 0;
		rep(i, n) ans += abs(a[i] - d);
		cout << ans << endl;
	}
}
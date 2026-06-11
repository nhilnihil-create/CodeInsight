#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i + 1;
	}

	sort(a.begin(),a.end());

	ll ans;
	if (n % 2 != 0) {
		ll b = a[n / 2];
		for (int i = 0; i < n; i++) {
			ans += abs(a[i] - b);
		}
	}
	else{
		ll ans_left = 0;
		ll ans_right = 0;
		ll b_left = a[n / 2 - 1];
		ll b_right = a[n / 2];

		for (int i = 0; i < n; i++) {
			ans_left += abs(a[i] - b_left);
			ans_right += abs(a[i] - b_right);			
		}
		ans = min(ans_left, ans_right);
	}

	cout << ans << endl;
	return 0;
}
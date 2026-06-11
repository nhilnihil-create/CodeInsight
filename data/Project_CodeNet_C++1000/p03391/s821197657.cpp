#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll sum = 0;
	ll mn = 1LL << 60;
	if(a == b) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, n) {
		sum += a[i];
		if(a[i] > b[i]) mn = min(mn, b[i]);
	}
	cout << sum - mn << endl;
	return 0;
}
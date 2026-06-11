#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	ll asum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		asum += a.at(i);
	}
	vector<ll>b(n);
	ll bsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> b.at(i);
		bsum += b.at(i);
	}
	if (asum < bsum) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll>a2b(n);
	for (int i = 0; i < n; i++) a2b.at(i) = a.at(i) - b.at(i);
	sort(a2b.begin(), a2b.end());
	ll minans = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a2b.at(i) < 0) {
			minans += a2b.at(i);
			ans++;
		}
		else break;
	}
	reverse(a2b.begin(), a2b.end());
	for (int i = 0; i < n; i++) {
		if (minans >= 0)break;
		ans++;
		minans += a2b.at(i);
	}
	cout << ans << endl;
}
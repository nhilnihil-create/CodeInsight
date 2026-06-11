#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	if (a.at(0) != 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (a.at(i) - a.at(i - 1) >= 2){
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (a.at(i) <= a.at(i - 1))ans+=a.at(i - 1);
	}
	ans += a.at(n - 1);
	cout << ans << endl;
}
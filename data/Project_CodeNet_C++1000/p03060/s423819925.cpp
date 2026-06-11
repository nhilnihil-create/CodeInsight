#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v.at(i);
	vector<int>c(n);
	for (int i = 0; i < n; i++)cin >> c.at(i);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += max(0, v.at(i) - c.at(i));
	}
	cout << ans << endl;
}
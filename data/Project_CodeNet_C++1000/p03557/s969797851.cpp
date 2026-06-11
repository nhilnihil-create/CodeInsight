#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int>a(n),b(n),c(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	for (int i = 0; i < n; i++) cin >> b.at(i);
	for (int i = 0; i < n; i++)cin >> c.at(i);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long as = lower_bound(a.begin(), a.end(), b.at(i)) - a.begin();
		long long cs = c.end() - upper_bound(c.begin(), c.end(), b.at(i));
		ans += as * cs;
	}
	cout << ans << endl;
}
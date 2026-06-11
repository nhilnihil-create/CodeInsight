#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0)ans += a.at(i);
		else if (a.at(i) > a.at(i - 1))ans += a.at(i) - a.at(i - 1);
	}
	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int>m(n);
	for (int i = 0; i < n; i++)cin >> m.at(i);
	for (int i = 0; i < n; i++)x -= m.at(i);
	sort(m.begin(), m.end());
	ll ans = n;
	ans += x / m.at(0);
	cout << ans << endl;
}
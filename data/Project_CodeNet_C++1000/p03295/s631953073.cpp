#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<ll,ll>>a(m);
	for (int i = 0; i < m; i++)cin >> a.at(i).first >> a.at(i).second;
	sort(a.begin(), a.end());
	ll l, r, p;
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			l = a.at(i).first;
			r = a.at(i).second;
		}
		else {
			if (a.at(i).first<r) {
				l = max(a.at(i).first, l);
				r = min(a.at(i).second, r);
			}
			else {
				ans++;
				l = a.at(i).first;
				r = a.at(i).second;
			}
		}
	}
	cout << ans + 1 << endl;
}
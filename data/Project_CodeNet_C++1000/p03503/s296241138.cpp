#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>f(n, vector<int>(10,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++)cin >> f.at(i).at(j);
	}
	vector<vector<int>>p(n, vector<int>(11,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			int x;
			cin >> x;
			p.at(i).at(j) = x;
		}
	}
	ll ans = -1e18;
	for (int bit = 1; bit < (1 << 10); bit++) {
		vector<int> l(0);
		for (int i = 0; i < 10; i++) if (bit & (1 << i))l.push_back(i);
		ll res = 0;
		vector<int>sy(n,0);
		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j < f.size(); j++) if (f.at(j).at(l.at(i)) == 1)sy.at(j)++;
		}
		for (int i = 0; i < sy.size(); i++) res += p.at(i).at(sy.at(i));
		ans = max(ans, res);
	}
	cout << ans << endl;
}
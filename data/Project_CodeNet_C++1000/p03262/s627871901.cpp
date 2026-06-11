#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	a.push_back(x);
	sort(a.begin(), a.end());
	vector<int>b;
	for (int i = 0; i < n; i++)b.push_back(a.at(i + 1) - a.at(i));
	sort(b.begin(), b.end());
	//数列の最大公約数を求める
	ll ans = 1;
	ll c = 2;
	while (c <= b.at(0)) {
		bool m = true;
		for (int i = 0; i < b.size(); i++) {
			if (b.at(i) % c != 0) {
				m = false;
				break;
			}
		}
		if (m) {
			ans *= c;
			for (int i = 0; i < b.size(); i++)b.at(i) /= c;
		}
		else c++;
	}
	cout << ans << endl;

}
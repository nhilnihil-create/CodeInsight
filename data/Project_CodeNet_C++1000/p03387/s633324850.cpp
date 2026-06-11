#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>a(3);
	cin >> a.at(0) >> a.at(1) >> a.at(2);
	sort(a.begin(), a.end());
	ll ans = 0;
	while (!(a.at(0) == a.at(1) && a.at(1) == a.at(2))) {
		if (a.at(1) - a.at(0) >= 2) {
			ans++;
			a.at(0) += 2;
		}
		else if (a.at(1) - a.at(0) == 1) {
			ans++;
			a.at(0)++;
			a.at(2)++;
		}
		else {
			int x = a.at(2) - a.at(1);
			ans += x;
			break;
		}
	}
	cout << ans << endl;
}
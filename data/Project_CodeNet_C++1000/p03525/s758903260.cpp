#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	if (n >= 25) {
		cout << 0 << endl;
		return 0;
	}
	vector<int>d(n);
	for (int i = 0; i < n; i++)cin >> d.at(i);
	sort(d.begin(), d.end());
	if (d.at(0)==0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n - 2; i++) {
		if (d.at(i) == d.at(i + 2)) {
			cout << 0 << endl;
			return 0;
		}
		if (d.at(i) == 12 && d.at(i + 1) == 12) {
			cout << 0 << endl;
			return 0;
		}
	}
	vector<int>tz(24,0);
	tz.at(0) = 1;
	for (int i = 0; i < n; i++)tz.at(d.at(i))++;
	vector<int>opz;
	for (int i = 1; i <= 11; i++) {
		if (tz.at(i) == 1) {
			opz.push_back(i);
			tz.at(i)--;
		}
		else if (tz.at(i) == 2) {
			tz.at(i)--;
			tz.at(24 - i)++;
		}
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << opz.size()); bit++) {
		vector<int>tzc = tz;
		vector<int> l(0);
		for (int i = 0; i < opz.size(); i++) {
			if (bit & (1 << i))tzc.at(opz.at(i))++;
			else tzc.at(24 - opz.at(i))++;
		}
		int res = 24;
		vector<int>tzd;
		for (int i = 0; i < 24; i++) {
			if (tzc.at(i) != 0)tzd.push_back(i);
		}
		for (int i = 1; i < tzd.size(); i++) {
			res = min(res, tzd.at(i) - tzd.at(i - 1));
		}
		res = min(res, 24 - tzd.at(tzd.size() - 1));
		ans = max(ans, res);
	}
	cout << ans << endl;
}
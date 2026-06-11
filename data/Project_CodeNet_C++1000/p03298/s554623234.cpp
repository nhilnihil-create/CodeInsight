#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n; string s;
	cin >> n >> s;
	vector<pair<string, string> > fw, bk;
	for (int i = 0; i < 1 << n; ++i) {
		string fwa, fwb, bka, bkb;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				fwa += s[j];
				bka += s[2 * n - j - 1];
			}
			else {
				fwb += s[j];
				bkb += s[2 * n - j - 1];
			}
		}
		fw.push_back(make_pair(fwa, fwb));
		bk.push_back(make_pair(bkb, bka));
	}
	sort(fw.begin(), fw.end());
	sort(bk.begin(), bk.end());
	long long ans = 0;
	for (pair<string, string> i : fw) {
		ans += upper_bound(bk.begin(), bk.end(), i) - lower_bound(bk.begin(), bk.end(), i);
	}
	cout << ans << endl;
	return 0;
}
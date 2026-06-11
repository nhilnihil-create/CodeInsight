#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int  p = 5;
	vector<pair<int,int>> pa;
	for (int i = 0; i < p; i++) {
		int s; cin >> s;
		pa.push_back({ s % 10, s });
	}
	sort(pa.begin(), pa.end());
	int ans = 0;
	int check = true;
	for (int i = 0; i < pa.size(); i++) {
		if (pa[i].first == 0) {
			ans += pa[i].second;
		}
		else {
			if (check) {
				ans += pa[i].second;
				check = false;
			}
			else {
				ans += (pa[i].second / 10 + 1) * 10;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
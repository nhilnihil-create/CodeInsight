#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string s;
int a[100005], n;

vector<P> ans;

int main() {
	cin >> s;
	rep(i, s.size()) {
		if (s[i] == '0') {
			a[i] = 0;
		}
		else a[i] = 1;
	}
	n = s.size();
	if (a[0] == 0 || a[n - 2] == 0 || a[n - 1] == 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - 2 - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	int now = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 1) {
			ans.push_back({ now, i + 1});
			now = i + 1;
		}
		else {
			ans.push_back({ now, i + 1});
		}
	}
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}
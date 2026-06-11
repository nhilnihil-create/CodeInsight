#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1 << 30;

int main() {
  int n;
	string s;
	cin >> n >> s;
	vector<int> l(n + 1), r(n + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') l[i + 1] = l[i] + 1;
		else l[i + 1] = l[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '.') r[i] = r[i + 1] + 1;
		else r[i] = r[i + 1];
	}
	int ans = INF;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, l[i] + r[i]);
	}
	cout << ans << endl;
	return 0;
}

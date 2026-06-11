#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1 << 30;

int main() {
  int n;
	string s;
	cin >> n >> s;
	vector<int> wh(n + 1), bl(n + 1);
	for (int i = 0; i < n; i++) {
		wh[i + 1] = wh[i] + (s[i] == '.' ? 1 : 0);
		bl[i + 1] = bl[i] + (s[i] == '#' ? 1 : 0);
	}
	int ans = INF;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, bl[i] - bl[0] + wh[n] - wh[i]);
	}
	cout << ans << endl;
	return 0;
}

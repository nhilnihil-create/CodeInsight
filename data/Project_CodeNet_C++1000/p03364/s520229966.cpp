#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n;
vector<string> s;

bool ok(int x, int y) {
	rep(i, n) {
		rep(j, i) {
			if(s[(x + i) % n][(y + j) % n] != s[(x + j) % n][(y + i) % n]) {
				return false;
			}
		}
	}
	return true;
}

signed main() {
	cin >> n;
	rep(i, n) {
		string w;
		cin >> w;
		s.push_back(w);
	}
	int ans = 0;
	rep(i, n) {
		if(ok(i, 0)) {
			ans += n - i;
		}
	}
	for(int i = 1; i < n; i++) {
		if(ok(0, i)) {
			ans += n - i;
		}
	}
	cout << ans << endl;
}
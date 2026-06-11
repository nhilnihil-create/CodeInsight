#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	string s;
	cin >> s;
	string t = "";
	rep(i,s.size()) if (s[i] != 'x') t = t + s[i];
	int tn = t.size() - 1;
	rep(i,t.size() / 2) {
		if (t[i] != t[tn - i]) {
			cout << -1 << endl;
			return;
		}
	}
	// if (t == "") {
	// 	cout << 0 << endl;
	// 	return;
	// }
	int l = 0;
	int r = s.size() - 1;
	int ans = 0;
	for (int i = 0; i < (t.size() + 1) / 2; i++) {
		while (s[l] == 'x' && s[r] == 'x') l++, r--;
		while (s[l] == 'x') {
			ans++;
			l++;
		}
		while (s[r] == 'x') {
			ans++;
			r--;
		}
		l++, r--;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
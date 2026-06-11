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
	string t;
	cin >> t;
	int n = s.size();
	int k = t.size();
	if (n < k) {
		cout << "UNRESTORABLE" << endl;
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		bool b = true;
		for (int j = 0; j < k; j++) {
			if (s[i - j] == '?' || s[i - j] == t[k - 1 - j]) continue;
			b = false;
		}
		if (b) {
			string ans = "";
			for (int j = 0; j < i - k + 1; j++) {
				if (s[j] == '?') ans += 'a';
				else ans += s[j];
			}
			ans += t;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == '?') ans += 'a';
				else ans += s[j];
			}
			cout << ans << endl;
			return;
		}
	}
	cout << "UNRESTORABLE" << endl;
}

int main() {
	solve();
	return 0;
}
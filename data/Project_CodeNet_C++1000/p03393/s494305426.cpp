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
	string is;
	rep(i,26) {
		is += 'z'- i;
	}
	if (is == s) {
		cout << -1 << endl;
		return;
	}
	vector<int> cnt(26);
	rep(i,26) {
		cnt[s[i] - 'a']++;
	}
	if (s.size() != 26) {
		char c;
		rep(i,26) {
			if (cnt[i] == 0) {
				c = 'a' + i;
				break;
			}
		}
		cout << s + c << endl;
	} else {
		string f;
		string t;
		for(int i = s.size() - 1; i >= 1; i--) {
			if (s[i-1] > s[i]) continue;
			f = s.substr(0, i);
			t = s.substr(i);
			break;
		}
		vector<int> cnt2(26);
		rep(i,t.size()) {
			cnt2[t[i] - 'a']++;
		}
		int p = f[f.size()-1] - 'a';
		char c;
		for (int i = p; i < 26; i++) {
			if (cnt2[i]) {
				c = 'a' + i;
				break;
			}
		}
		string ans = "";
		rep(i,f.size()) {
			if (i == f.size() - 1) ans = ans + c;
			else ans = ans + f[i];
		}
		cout << ans << endl;
	}

}

int main() {
	solve();
	return 0;
}
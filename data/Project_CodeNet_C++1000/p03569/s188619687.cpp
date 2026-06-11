#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;
bool rev(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}
signed main() {
	string s; cin >> s;
	string remx;
	rep(i, s.size())if (s[i] != 'x')remx.push_back(s[i]);
	if (rev(remx)) {
		s = "x" + s + "x";
		vector<int>cnt;
		int cx = 0;
		rep(i, s.size()) {
			if (s[i] == 'x')cx++;
			else {
				cnt.push_back(cx);
				cx = 0;
			}
		}
		cnt.push_back(cx);
		int ans = 0;
		rep(i, cnt.size() / 2) {
			ans += abs(cnt[i] - cnt[cnt.size() - 1 - i]);
		}
		cout << ans << endl;
	}
	else cout << -1 << endl;
}
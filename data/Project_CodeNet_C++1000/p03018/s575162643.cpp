#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

ll f(string s) {
	ll res = 0, a = 0;
	rep(i, s.size()) {
		if (s[i] == 'a') a++;
		else res += a;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	string t;
	ll ans = 0;
	int n = s.size(); s += 'X';
	rep(i, n) {
		if (s[i] == 'A') t += 'a';
		else if (s[i] == 'C') {
			ans += f(t);
			t = "";
		}
		else {
			if (s[i + 1] == 'C') t += 'b', ++i;
			else ans += f(t), t = "";
		}
	}
	ans += f(t);
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	int cntb_ = 0, cnt_a = 0, cntba = 0, sub = 0;

	rep(i, 0, n) {
		string s; cin >> s;

		rep(j, 0, sz(s) - 1) if (s.substr(j, 2) == "AB") sub++;

		if (s[0] == 'B' && s.back() == 'A') cntba++;
		else if (s[0] == 'B') cntb_++;
		else if (s.back() == 'A') cnt_a++;
	}

	cout << (sub + cntba + min(cntb_, cnt_a) - int(cntba && !cntb_ && !cnt_a)) << endl;
}

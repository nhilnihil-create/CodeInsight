#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ps[200005][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	string s; cin >> s;
	s = " " + s;

	// W*B*
	rep(i, 1, s.size()) {
		ps[i][0] = ps[i - 1][0] + int(s[i] == '#');
		ps[i][1] = ps[i - 1][1] + int(s[i] == '.');
	}

	int ans = 9999999;
	rep(i, 0, s.size()) {
		//printf("%d; Left B %d; Right W %d\n", i, ps[i][0], ps[n][1] - ps[i][1]);
		ans = min(ans, ps[i][0] + (ps[n][1] - ps[i][1]));
	}
	cout << ans << endl;
}

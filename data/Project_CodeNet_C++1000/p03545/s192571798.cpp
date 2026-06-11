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
	rep(i,(1 << 3)) {
		int x = s[0] - '0';
		rep(j,3) {
			if (i & (1 << j)) {
				x += s[j+1] - '0';
			} else {
				x -= s[j+1] - '0';
			}
		}
		if (x == 7) {
			string t = s.substr(0, 1);
			rep(j,3) {
				if (i & (1 << j)) {
					t = t + "+" + s[j + 1];
				} else {
					t = t + "-" + s[j + 1];
				}
			}
			cout << t + "=7" << endl;
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}
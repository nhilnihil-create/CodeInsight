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

struct mint {
	ll x;
	mint(ll x = 0) :x(x% mod) {}
	mint& operator+=(const mint a) {
		(x += a.x) %= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		(x += mod - a.x) %= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
};

mint dp[100005][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = n; i >= 0; --i) {
		for (int j = 3; j >= 0; --j) {
			if (i == n) {
				dp[i][j] = (j == 3 ? 1 : 0);
			}
			else {
				dp[i][j] = dp[i + 1][j] * (s[i] == '?' ? 3ll : 1ll);
				if (j < 3 && (s[i] == '?' || s[i] == "ABC"[j])) {
					dp[i][j] += dp[i + 1][j + 1];
				}
			}
		}
	}
	mint ans = dp[0][0];
	cout << ans.x << endl;
	return 0;
}

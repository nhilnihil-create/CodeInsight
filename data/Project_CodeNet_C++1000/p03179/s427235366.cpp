#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod= 1e9 + 7;


int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	//各文字処理時において、前の文字より大きい文字がどれだけ残っているかわかればよい。
	//dp[i][j]...i番目の文字において、i-1番目の文字より大きい文字がj個残っているときの場合の数
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	vector<vector<ll>> sums(n, vector<ll>(n+1, 0));
	rep(i, n) {
		//任意の数なので1とする
		dp[0][i] = 1;
		sums[0][i + 1] = sums[0][i] + dp[0][i];
	}
	for (int i = 0; i < n-1; i++) {
		char c = s[i];
		if (c == '<') {
			for (int j = 0; j < n-i-1; j++) {
				//j==0...0個
				//dp[i + 1][0] = dp[i][1] + dp[i][2] + ... + dp[i][n - i - 1];
				//j==1...
				//dp[i + 1][1] = dp[i][2] + dp[i][3] + ... + dp[i][n - i - 1];
				//dp[i + 1][n - i - 2] = dp[i][n - 1 - i];

				dp[i + 1][j] = sums[i][n - i] - sums[i][j+1] + mod;
				dp[i + 1][j] %= mod;
			}
		}
		else {
			for (int j = 0; j < n-i; j++) {
				//j==0...0個
				//dp[i + 1][0] = dp[i][0];
				//j==1...
				//dp[i + 1][1] = dp[i][0] + dp[i][1];
				//j==2...
				//dp[i + 1][2] = dp[i][0] + dp[i][1] + dp[i][2];
				dp[i + 1][j] = sums[i][j+1] - sums[i][0] + mod;
				dp[i + 1][j] %= mod;
			}
		}
		rep(j, n) {
			sums[i + 1][j + 1] = sums[i + 1][j] + dp[i + 1][j];
			sums[i + 1][j + 1] %= mod;
		}
	}
	cout << sums[n - 1][1] << endl;
	return 0;
}
	
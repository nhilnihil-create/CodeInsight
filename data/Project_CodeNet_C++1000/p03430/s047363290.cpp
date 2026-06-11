#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int dp[301][301][302] = {};
int main() {
	string s; cin >> s; int n = s.length();
	int c; cin >> c;
	rep(i, n) {
		rep(k, c+1) {
			rep(j, n+1) {
				if (j < n) {
					if (s[i] == s[n - 1 - j]) {
						dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + 1);
					}
					if (k < c) {
						dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + 1);
					}
					dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
				}
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	int out = 0;
	rep(i, n + 1) {
		rep(j, n + 1) {
			rep(k, c+1) {
				if (i + j == n) {
					out = max(out, 2*dp[i][j][k]);
				}
				else if (i + j == n - 1) {
					out = max(out, 1 + 2 * dp[i][j][k]);
				}
			}
		}
	}
	cout << out << endl;
	return 0;
}
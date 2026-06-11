#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	vector<vector<ll>> l(n);
	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		l[i].push_back(a);
		l[i].push_back(b);
		l[i].push_back(c);
	}

	vector<vector<ll>> dp(100010, vector<ll>(3, -1));
	rep(i, 3) {
		dp[0][i] = 0;
	}
	rep(i, n) {
		rep(j, 3) {
			rep(k, 3) {
				if (j != k) {
					chmax(dp[i + 1][k], dp[i][j] + l[i][k]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i, 3) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}
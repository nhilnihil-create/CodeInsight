#include "bits/stdc++.h"
#include<cassert>
#pragma warning(disable:4996)
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MRE assert(0)
const int mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P, int>PP;
int dp[305][305][305];
string s; int K, n;
void DP() {
	rep(k, K + 1) {
		rep(i, n) {//幅
			for (int j = 0; j + i < n; j++) {//[j,j+i]
				if (j) {
					dp[j - 1][j + i][k] = max(dp[j - 1][j + i][k], dp[j][j + i][k]);
				}
				if (j + i < n - 1) {
					dp[j][j + i + 1][k] = max(dp[j][j + i + 1][k], dp[j][j + i][k]);
				}
				if (j&&j + i < n - 1) {
					if (s[j - 1] == s[j + i + 1]) {
						dp[j - 1][j + i + 1][k] = max(dp[j - 1][j + i + 1][k], dp[j][j + i][k] + 2);
					}
					else if (k != K) {
						dp[j - 1][j + i + 1][k + 1] = max(dp[j - 1][j + i + 1][k + 1], dp[j][j + i][k] + 2);
					}
				}
			}
		}
	}
}

signed main() {
	cin >> s; cin >> K; n = s.size();
	rep(i, n)dp[i][i][0] = 1;
	DP();
	int res = 0,res2=0;
	rep(i, n)rep(j, n)rep(k, K + 1)res = max(res, dp[i][j][k]);
	rep(i, n)rep(j, n)rep(k, K + 1)dp[i][j][k] = 0;
	rep(i, n-1) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j])dp[i][j][0] = 2;
			else dp[i][j][1] = 2;
		}
	}
	DP();
	rep(i, n)rep(j, n)rep(k, K + 1)res2 = max(res2, dp[i][j][k]);
	cout <<max(res,res2)<< endl;
}
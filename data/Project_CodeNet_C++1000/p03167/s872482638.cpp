#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX / 5
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

signed main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>>A(H, vector<char>(W));
	rep(i, H) {
		rep(j, W) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>>dp(H, vector<int>(W));
	rep(i, H) {
		rep(j, W) {
			if (A[i][j] == '#') {
				dp[i][j] = 0;
			}
			else {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
				}
				else if (i == 0) {
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[H - 1][W - 1] << endl;
}
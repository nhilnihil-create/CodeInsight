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
	int N;
	cin >> N;
	vector<double>p(N);
	rep(i, N) {
		cin >> p[i];
	}
	vector<vector<double>>dp(N + 1, vector<double>(2 * N + 3));
	rep(i, N + 1) {
		for (int j = (-1) * N; j <= N; j++) {
			if (i == 0) {
				if (j == 0) {
					dp[i][N+1+j] = 1;
				}
				else {
					dp[i][N+1+j] = 0;
				}
			}
			else {
				dp[i][N + 1 + j] = dp[i - 1][N + j] * (1 - p[i - 1]) + dp[i - 1][N + 2 + j] * p[i - 1];
			}
		}
	}

	/*
	rep(i, N + 1) {
		for (int j = (-1) * N; j <= N; j++) {
			cout << dp[i][N + 1 + j] << ' ';
		}
		cout << endl;
	}
	*/

	
	double ans = 0;
	rep(i, N + 1) {
		for (int j = (-1) * N; j <= N; j++) {
			if (i == N && j < 0) {
				ans += dp[i][N + 1 + j];
			}
		}
	}
	cout << fixed << setprecision(20) << ans << endl;
	//cout << ans << endl;
	
}
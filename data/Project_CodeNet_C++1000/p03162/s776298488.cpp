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
	vector<int>A(N);
	vector<int>B(N);
	vector<int>C(N);
	rep(i, N) {
		cin >> A[i] >> B[i] >> C[i];
	}
	vector<vector<int>>dp(N, vector<int>(3));
	rep(i, N) {
		if (i == 0) {
			dp[i][0] = A[i];
			dp[i][1] = B[i];
			dp[i][2] = C[i];
		}
		else {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + A[i];
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + B[i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + C[i];
		}
	}
	cout << max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << enld;
}
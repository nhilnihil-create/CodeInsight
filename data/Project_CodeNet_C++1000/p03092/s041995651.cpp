#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;

int C[maxn];
ll dp[maxn][maxn], A, B;
int n, where[maxn], a[maxn];

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	cin >> n >> A >> B;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		where[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		int c = 0;
		for(int j = 1; j < i; j++) {
			if(where[j] < where[i])
				c++;
		}
		C[i] = c + 1;
	}
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(C[i] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = min(dp[i - 1][j - 1] + A, dp[i - 1][C[i] - 1] + (j - C[i]) * B);
			}
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}
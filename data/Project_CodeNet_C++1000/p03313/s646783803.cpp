#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N;
ll A[1 << 18];
P dp[19][1 << 18];

int main() {
	cin >> N;
	for (int i = 0; i < (1 << N); i++) {
		cin >> A[i];
	}
	for (int i = 0; i < (1 << N); i++)dp[0][i].first = A[i], dp[0][i].second = -1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (1 << N); j++) {
			dp[i][j] = dp[i - 1][j];
			if (j & (1 << (i - 1))) {
				int ar[4];
				ar[0] = dp[i][j].first, ar[1] = dp[i][j].second;
				ar[2] = dp[i - 1][j - (1 << (i - 1))].first, ar[3] = dp[i - 1][j - (1 << (i - 1))].second;
				sort(ar, ar + 4);
				dp[i][j] = make_pair(ar[3], ar[2]);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i < (1 << N); i++) {
		ans = max(ans, dp[N][i].first + dp[N][i].second);
		cout << ans << endl;
	}
	return 0;
}
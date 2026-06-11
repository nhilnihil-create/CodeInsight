#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

const int MAXN = 5010;
int N;
ll A, B;
int P[MAXN];
ll dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	P[0] = 0;
	P[N+1] = N+1;

	dp[0] = 0;
	for (int i = 1; i <= N+1; i++) {
		dp[i] = INF;
		int numBigger = 0;
		for (int j = i-1; j >= 0; j--) {
			if (P[j] < P[i]) {
				dp[i] = min(dp[i], dp[j] + numBigger * A + (i-j-1-numBigger) * B);
			} else {
				numBigger++;
			}
		}
	}
	cout << dp[N+1] << '\n';

	return 0;
}

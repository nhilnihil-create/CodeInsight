
// C - Strange Bank

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int dp[100001]; // dp[k]: k円引き出すのに必要な最小の回数

int main() {
	int N;
	cin >> N;

	vector<int> withdraw;

	withdraw.push_back(1);

	for (int i=1; pow(6, i) <= 100000; i++) {
		withdraw.push_back(pow(6, i));
	}

	for (int i=1; pow(9, i) <= 100000; i++) {
		withdraw.push_back(pow(9, i));
	}

	for (int i=1; i<=N; i++) {
		dp[i] = INF;
	}

	for (int w : withdraw) {
		for (int i=0; i<N; i++) {
			if (i + w <= 100000) {
				dp[i + w] = min(dp[i + w], dp[i] + 1);
			}
		}
	}

	cout << dp[N] << endl;

	return 0;
}
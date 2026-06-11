#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 62;
int main() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<int> p(N);
	for (int i = 0; i < N; ++i) cin >> p[i], --p[i];
	vector<long long> dp(N);
	for (int i = 0; i < N; ++i) {
		long long nxt = inf;
		for (int j = 0; j <= p[i]; ++j) {
			nxt = min(nxt, dp[j]);
		}
		for (int j = 0; j < N; ++j) {
			if (j < p[i]) dp[j] += A;
			else dp[j] += B;
		}
		dp[p[i]] = min(dp[p[i]], nxt);
	}
	cout << *min_element(dp.begin(), dp.end()) << endl;
	return 0;
}
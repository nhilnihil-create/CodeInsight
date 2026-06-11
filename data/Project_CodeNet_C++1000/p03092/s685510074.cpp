#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2>
inline bool cmn (T1& a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	constexpr long long inf = 1LL << 60;
	int n, A, B;
	cin >> n >> A >> B;
	vector<long long> p(n + 2);
	for (int i = 1; i <= n; i++) cin >> p[i];
	p[0] = 0; p[n + 1] = n + 1;
	vector<long long> dp(n + 2, inf);
	dp[0] = 0;
	for (int i = 1; i <= n + 1; i++) {
		long long tmp = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (p[j] < p[i]) {
				cmn(dp[i], dp[j] + tmp);
				tmp += B;
			} else {
				tmp += A;
			}
		}
	}
	cout << dp[n + 1] << endl;
	return 0;
}
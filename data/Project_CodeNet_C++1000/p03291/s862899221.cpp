#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	ULL M = 1000000007;

	void Solve() {
		ULL dp[4] = {}; dp[0] = 1;
		string T; cin >> T;
		rep(i, T.size()) {
			if (T[i] == 'A') {
				dp[1] += dp[0];
				dp[1] %= M;
			}
			else if (T[i] == 'B') {
				dp[2] += dp[1];
				dp[2] %= M;
			}
			else if (T[i] == 'C') {
				dp[3] += dp[2];
				dp[3] %= M;
			}
			else {
				dp[3] = dp[3] * 3 + dp[2]; dp[3] %= M;
				dp[2] = dp[2] * 3 + dp[1]; dp[2] %= M;
				dp[1] = dp[1] * 3 + dp[0]; dp[1] %= M;
				dp[0] *= 3; dp[0] %= M;
			}
		}
		cout << dp[3] << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}

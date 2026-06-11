#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> C(N); rep(i, N) { cin >> C[i]; C[i]--; }
		vector<ULL> dp(N + 1); dp[0] = 1;
		vector<UL> P(N);
		vector<UL> CP; CP.assign(200000, (UL)-1);
		rep(i, N) {
			P[i] = CP[C[i]]; CP[C[i]] = i;
		}
		//rep(i, N) cout << P[i] << " "; cout << endl;
		rep(i, N) {
			dp[i + 1] = dp[i];
			if (P[i] != -1) if (P[i] != i - 1) dp[i + 1] += dp[P[i] + 1];
			dp[i + 1] %= 1000000007;
		}
		//rep(i, N) cout << dp[i] << " ";
		cout << dp[N] << endl;
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
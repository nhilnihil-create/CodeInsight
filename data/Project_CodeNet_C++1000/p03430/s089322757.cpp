#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL dp[301][301][301] = {};

	void Solve() {
		string S; cin >> S;
		string rS = S; reverse(rS.begin(), rS.end());
		UL K; cin >> K;
		UL ans = 1;
		for (UL i = 0; i < S.size(); i++) {
			for (UL j = 0; j < rS.size(); j++) {
				if ((i + 1) + (j + 1) > S.size()) continue;
				for (UL k = 0; k <= K; k++) {
					auto &p = dp[i + 1][j + 1][k];
					p = max(p, dp[i][j + 1][k]);
					p = max(p, dp[i + 1][j][k]);
					if (S[i] == rS[j]) p = max(p, dp[i][j][k] + 1);
					if (k != 0) p = max(p, dp[i][j][k - 1] + 1);
					if ((i + 1) + (j + 1) == S.size()) ans = max(ans, p * 2);
					if ((i + 1) + (j + 1) == S.size() - 1) ans = max(ans, p * 2 + 1);
				}
			}
		}
		/*
		for (UL k = 0; k <= K; k++) {
			for (UL i = 0; i <= S.size(); i++) {
				for (UL j = 0; j <= rS.size(); j++) {
					cout << dp[i][j][k] << " ";
				} cout << endl;
			} cout << endl;
		}*/
		cout << ans << endl;
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
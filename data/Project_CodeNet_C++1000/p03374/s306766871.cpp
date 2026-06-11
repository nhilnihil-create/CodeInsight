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
		LL C; cin >> C;
		vector<pair<LL, LL>> X(N);
		rep(i, N) cin >> X[i].first >> X[i].second;
		auto rX = X;
		reverse(rX.begin(), rX.end());
		rep(i, N) rX[i].first = C - rX[i].first;
		rep(i, N - 1) {
			X[i + 1].second += X[i].second;
			rX[i + 1].second += rX[i].second;
		}

		LL ans = 0;
		LL M = 0;
		rep(i, N) {
			ans = max(ans, M + rX[N - i - 1].second - rX[N - i - 1].first);
			M = max(M, X[i].second - 2 * X[i].first);
		}
		M = 0;
		rep(i, N) {
			ans = max(ans, M + X[N - i - 1].second - X[N - i - 1].first);
			M = max(M, rX[i].second - 2 * rX[i].first);
		}
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

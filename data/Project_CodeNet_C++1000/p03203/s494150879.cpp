#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL H, W; cin >> H >> W;
		UL N; cin >> N;
		vector<pair<UL, UL>> P(N);
		rep(i, N) cin >> P[i].first >> P[i].second;
		sort(P.begin(), P.end());
		UL ans = H;
		UL by = 0;
		rep(i, N) {
			if (P[i].first == P[i].second + by) by++;
			if (P[i].first > P[i].second + by) {
				cout << P[i].first - 1 << endl;
				return;
			}
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

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
		vector<pair<LL, LL>> R(N);
		rep(i, N) cin >> R[i].first >> R[i].second;
		R.push_back({ 0, 0 });
		LL l = -100001, r = 100001;
		while (l + 1 < r) {
			LL m = (l + r) / 2;
			UL a = 0, b = 0;
			rep(i, N + 1) {
				if (m < R[i].first) b++;
				if (R[i].second < m) a++;
			}
			if (a <= b) l = m;
			else r = m;
		}
		LL ans = 0;
		for (LL O : {l, r}) {
			LL ansbuf = 0;
			vector<UL> Ls, Rs;
			rep(i, N) {
				if (O <= R[i].first) Ls.push_back(R[i].first - O);
				if (R[i].second <= O) Rs.push_back(O - R[i].second);
			}
			sort(Ls.begin(), Ls.end());
			sort(Rs.begin(), Rs.end());
			if (O <= 0) Ls.push_back(-O);
			if (0 <= O) Rs.push_back(O);
			reverse(Ls.begin(), Ls.end());
			reverse(Rs.begin(), Rs.end());
			rep(i, min(Ls.size(), Rs.size())) {
				ansbuf += Ls[i] + Rs[i];
			}
			ans = max(ansbuf, ans);
		}
		ans *= 2;
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
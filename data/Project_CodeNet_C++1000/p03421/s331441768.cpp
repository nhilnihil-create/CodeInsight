#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, A, B; cin >> N >> A >> B;
		if (N < A + B - 1) { cout << -1 << endl; return; }
		if (N > A * B) { cout << -1 << endl; return; }
		vector<UL> ans;
		UL s = N;
		UL t = 0;
		while (B != t + s) {
			if (A + B - t <= s) {
				s -= A;
				rep(i, A) {
					ans.push_back(s + i + 1);
				}
			}
			else {
				UL l = s - (B - t - 1);
				s -= l;
				rep(i, l) {
					ans.push_back(s + i + 1);
				}
			}
			t++;
		}
		rep(i, s) ans.push_back(s - i);

		rep(i, ans.size()) { if (i) cout << " "; cout << ans[i]; }
		cout << endl;
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

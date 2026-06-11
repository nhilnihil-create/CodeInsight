#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL A, B; cin >> A >> B;
		UL Q; cin >> Q;
		set<LL> shrine; rep(i, A) { LL x; cin >> x; shrine.insert(x); }
		set<LL> temple; rep(i, B) { LL x; cin >> x; temple.insert(x); }
		shrine.insert(-1e11); shrine.insert(-1e11); shrine.insert(1e11); shrine.insert(1e11);
		temple.insert(-1e11); temple.insert(-1e11); temple.insert(1e11); temple.insert(1e11);
		rep(i, Q) {
			LL X; cin >> X;
			LL ans = 1e11;
			LL nSh[2], nTm[2];
			{
				auto itr = shrine.upper_bound(X);
				nSh[1] = *itr - X; itr--; nSh[0] = X - *itr;
			}
			{
				auto itr = temple.upper_bound(X);
				nTm[1] = *itr - X; itr--; nTm[0] = X - *itr;
			}
			ans = min(ans, max(nSh[0], nTm[0]));
			ans = min(ans, max(nSh[1], nTm[1]));
			ans = min(ans, min(nSh[0], nTm[1]) + nSh[0] + nTm[1]);
			ans = min(ans, min(nSh[1], nTm[0]) + nSh[1] + nTm[0]);
			cout << ans << endl;
		}
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

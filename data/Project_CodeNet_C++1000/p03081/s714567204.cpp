#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, Q; cin >> N >> Q;
		string S; cin >> S;
		vector<pair<char, char>> A(Q);
		rep(i, Q) cin >> A[i].first >> A[i].second;
		UL L, R;
		UL l = 0, r = N + 1;
		while(l + 1 < r){
			UL m = (l + r) >> 1;
			UL p = m - 1;
			rep(i, Q) {
				if (S[p] == A[i].first) {
					if (A[i].second == 'L') p--;
					if (A[i].second == 'R') p++;
				}
				if (p == -1) break;
				if (p == N) break;
			}
			if (p == -1) l = m; else r = m;
		}
		L = l;
		l = 0; r = N + 1;
		while (l + 1 < r) {
			UL m = (l + r) >> 1;
			UL p = m - 1;
			rep(i, Q) {
				if (S[p] == A[i].first) {
					if (A[i].second == 'L') p--;
					if (A[i].second == 'R') p++;
				}
				if (p == -1) break;
				if (p == N) break;
			}
			if (p == N) r = m; else l = m;
		}
		R = l;
		UL ans = R - L;
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
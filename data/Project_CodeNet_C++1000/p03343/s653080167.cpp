#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, K, Q; cin >> N >> K >> Q;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		vector<pair<UL, UL>> sorted; rep(i, N) sorted.push_back({ A[i], i });
		sort(sorted.begin(), sorted.end());
		vector<UL> used(N + 1); used[N] = 1;
		UL ans = 1000000001;
		rep(i, N) {
			vector<UL> L;
			vector<UL> buf;
			rep(j, N + 1) {
				if (used[j]) {
					sort(buf.begin(), buf.end());
					if (buf.size() >= K)
						for (UL k = 0; k <= buf.size() - K; k++)
							L.push_back(buf[k]);
					buf.clear();
				}
				else { buf.push_back(A[j]); }
			}
			//rep(j, L.size()) cout << L[j] << " "; cout << endl;
			if (L.size() < Q) break;
			sort(L.begin(), L.end());
			ans = min(ans, L[Q - 1] - L[0]);
			used[sorted[i].second] = 1;
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

#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
	
	void Solve() {
		UL N; cin >> N;
		UL K; cin >> K;
		UL A[1000]; rep(i, N) cin >> A[i];
		vector<ULL> AA;
		for (UL i = 0; i < N; i++) {
			ULL S = 0;
			for (UL j = i; j < N; j++) {
				S += A[j];
				AA.push_back(S);
			}
		}
		ULL ans = 0;
		for (ULL M = 1ull << 40; M != 0; M >>= 1) {
			UL n = 0;
			rep(i, AA.size()) if (AA[i] & M) n++;
			if (n >= K) {
				UL p = 0;
				while (p < AA.size()) {
					if ((AA[p] & M) == 0) {
						swap(AA[p], AA.back());
						AA.pop_back();
					}
					else p++;
				}
				ans |= M;
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

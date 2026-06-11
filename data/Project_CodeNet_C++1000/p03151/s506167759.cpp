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
		ULL SC, SB; SC = 0; SB = 0;
		vector<UL> A(N), B(N);
		rep(i, N) cin >> A[i];
		rep(i, N) cin >> B[i];
		rep(i, N) { SC += A[i]; SB += B[i]; }
		if (SB > SC) { cout << -1 << endl; return; }
		LL K = 0;
		vector<UL> Sp;
		UL ans = 0;
		rep(i, N) {
			if (A[i] < B[i]) { K += (B[i] - A[i]); ans++; }
			if (A[i] > B[i]) Sp.push_back(A[i] - B[i]);
		}
		sort(Sp.begin(), Sp.end());
		while (K > 0) {
			UL p = Sp.back(); Sp.pop_back();
			K -= p;
			ans++;
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
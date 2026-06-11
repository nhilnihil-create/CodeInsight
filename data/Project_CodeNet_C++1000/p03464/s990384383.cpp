#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve(){
		UL N; cin >> N;
		vector<ULL> A(N); rep(i, N) cin >> A[i];
		reverse(A.begin(), A.end());
		ULL L, R; L = R = 2;
		rep(i, N) {
			ULL a = A[i];
			L = (L - 1) / a * a + a;
			R = R / a * a + (a - 1);
			if (L > R) { cout << -1 << endl; return; }
		}
		cout << L << " " << R << endl;
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
#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
	
	void Solve() {
		int N; cin >> N;
		int A[100];
		int SA = 0;
		rep(i, N) cin >> A[i];
		rep(i, N) SA += A[i];
		UL p = 0;
		rep(i, N) { A[i] = abs(A[i] * N - SA); }
		rep(i, N) {
			if (A[p] > A[i]) p = i;
		}
		cout << p << endl;
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

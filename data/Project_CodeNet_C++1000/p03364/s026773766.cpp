#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL A[300][600];

	void Solve(){
		UL N; cin >> N;
		rep(y, N) rep(x, N) {
			char c; cin >> c;
			A[x][y + N] = A[x][y] = (UL)c;
		}
		UL ans = 0;
		rep(i, N) {
			bool ok = true;
			rep(y, N) rep(x, N) {
				if (A[x][y + i] != A[y][x + i]) ok = false;
			}
			if (ok) ans++;
		}
		cout << (ans * N) << endl;
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
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
		UL A, B; cin >> A >> B;
		vector<UL> P(N); rep(i, N) cin >> P[i];
		UL S[3] = {};
		rep(i, N) {
			if (P[i] <= A) S[0]++;
			else if (P[i] > B) S[2]++;
			else S[1]++;
		}
		UL ans = min(S[0], min(S[1], S[2]));
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
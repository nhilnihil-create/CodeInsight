#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		multiset<UL> A; rep(i, N) { UL a; cin >> a; A.insert(a); }
		UL ans = 0;
		while (A.size()) {
			UL p = *(--A.end()); A.erase(--A.end());
			UL q = 1; while (q <= p) q <<= 1; q -= p;
			auto i = A.find(q);
			if (i == A.end()) continue;
			ans++;
			//cout << p << " " << q << endl;
			A.erase(i);
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
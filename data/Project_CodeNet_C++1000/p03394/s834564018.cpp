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
		UL L = N / 2;
		UL R = N - L;
		if (N == 19999) { L = 10000; R = 9999; }
		if (N == 19998) { L = 10000; R = 9998; }
		vector<UL> ans;
		if (N == 3) { cout << "2 5 63" << endl; return; }
		{
			UL p;
			if (R % 4 == 0) { p = 3; }
			if (R % 4 == 1) { ans.push_back(6); p = 9; }
			if (R % 4 == 2) { ans.push_back(3); ans.push_back(9); p = 12; }
			if (R % 4 == 3) { ans.push_back(3); ans.push_back(6); ans.push_back(9); p = 12; }
			R -= R % 4;
			rep(i, R) { ans.push_back(p); p += 3; }
		}
		{
			UL p = 2;
			if (L % 2 == 1) { ans.push_back(2); ans.push_back(8); ans.push_back(14); p = 20; L -= 3; }
			L /= 2;
			rep(i, L) { ans.push_back(p); ans.push_back(p + 2); p += 6; }
		}

		rep(i, ans.size()) { if (i) cout << " "; cout << ans[i]; }
		cout << endl;
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
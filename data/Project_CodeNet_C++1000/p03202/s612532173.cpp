#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL N;
	vector<UL> A;

	bool Loop(UL K) {
		if (K == 1) {
			bool ok = true;
			rep(i, N - 1) if (A[i] >= A[i + 1]) ok = false;
			return ok;
		}
		vector<pair<UL, UL>> C;
		C.push_back({ 0, 0 });
		rep(i, N) {
			//rep(j, C.size()) { cout << "{" << C[j].first << "," << C[j].second << "}" << ","; }
			//cout << endl;
			if (C.back().first < A[i]) { C.push_back({ A[i], 0 }); continue; }
			while (C.back().first > A[i]) C.pop_back();
			if (C.back().first < A[i]) { C.push_back({ A[i], 1 }); continue; }
			UL p = C.back().first;
			while (true) {
				if (C.back().first != p) { C.push_back({ p, 1 }); break; }
				C.back().second++;
				if (C.back().second != K) break;
				if (p == 1) {
					//cout << "NG : K = " << K << endl;
					return false;
				}
				C.pop_back();
				p--;
			}
		}
		//rep(j, C.size()) { cout << "{" << C[j].first << "," << C[j].second << "}" << ","; }
		//cout << endl;
		//cout << "OK : K = " << K << endl;
		return true;
	}

	void Solve() {
		cin >> N;
		A.resize(N); rep(i, N) cin >> A[i];
		UL l = 0, r = N;
		while (l + 1 < r) {
			UL m = (l + r + 1) >> 1;
			//cout << "ATTEMPT : K = " << m << endl;
			if (Loop(m)) r = m; else l = m;
		}
		cout << r << endl;
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
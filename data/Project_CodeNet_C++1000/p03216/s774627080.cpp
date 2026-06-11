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
		string S; cin >> S;
		UL Q; cin >> Q;
		/*
		//pair<UL, UL> K[75]; rep(i, Q) { cin >> K[i].first; K[i].second = i; }
		//sort(K, K + Q);
		vector<ULL> DM(N);
		{
			ULL D = 0, Dm = 0;
			rep(i, N) {
				if (S[i] == 'D') D++;
				if (S[i] == 'M') Dm += D;
				DM[i] = Dm;
				cout << Dm << " ";
			}cout << endl;
		}
		UL K[75]; rep(i, Q) cin >> K[i];
		rep(i, Q) {
			ULL ans = 0;
			UL k = K[i];
			for (UL j = 0; j < k; j++) {
				if (S[j] == 'C') ans += DM[j];
			}
			for (UL j = k; j < N; j++) {
				if (S[j] == 'C') ans += DM[j] - DM[j - k];
			}
			cout << ans << endl;
		}
		*/
		rep(q, Q) {
			ULL ans = 0;
			UL k; cin >> k;
			UL D = 0;
			UL M = 0;
			ULL DM = 0;
			for (UL i = 0; i < k; i++) {
				if (S[i] == 'D') { D++; }
				if (S[i] == 'M') { M++; DM += D; }
				if (S[i] == 'C') { ans += DM; }
			}
			for (UL i = k; i < N; i++) {
				if (S[i - k] == 'D') { DM -= M; D--; }
				if (S[i - k] == 'M') { M--; }
				if (S[i] == 'D') D++;
				if (S[i] == 'M') { M++; DM += D; }
				if (S[i] == 'C') { ans += DM; }
			}
			cout << ans << endl;
		}
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

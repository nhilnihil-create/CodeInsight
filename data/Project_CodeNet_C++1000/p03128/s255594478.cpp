#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	void Solve() {
		UL N; cin >> N;
		UL M; cin >> M;
		vector<UL> A(M); rep(i, M) cin >> A[i];
		UL S[10] = { 0,2,5,5,4,5,6,3,7,6 };
		pair<UL, UL> G = { 0,0 };
		rep(i, M) {
			pair<UL, UL> B = { 10 - S[A[i]], A[i] };
			G = max(G, B);
		}
		G.first = 10 - G.first;
		UL Sz = min(G.first * 7 + (N % G.first), N);
		vector<UL> dp(Sz + 1, -1);
		dp[Sz] = 0;
		for (UL j = Sz; j != -1; j--) {
			rep(i, M) {
				if (j + S[A[i]] > Sz) continue;
				if (dp[j + S[A[i]]] == -1) continue;
				if (dp[j] == -1) dp[j] = 0;
				dp[j] = max(dp[j], dp[j + S[A[i]]] * 10 + A[i]);
			}
		}
		string Z = to_string(dp[0]);
		rep(i, Z.size()) if (Z[i] - '0' >= G.second) cout << Z[i];
		rep(i, (N - Sz) / G.first) cout << G.second;
		rep(i, Z.size()) if (Z[i] - '0' < G.second) cout << Z[i];
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

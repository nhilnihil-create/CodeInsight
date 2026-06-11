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
		vector<pair<UL, UL>> ans;
		vector<vector<UL>> G;
		if (N & 1) G.push_back({ N });
		UL Np = N / 2 * 2;
		rep(i, N / 2) G.push_back({ i + 1, Np - i });
		rep(i, G.size() - 1) {
			for (UL a : G[i]) for (UL b : G[i + 1]) {
				ans.push_back({ a, b });
			}
		}
		if(G.size() > 2) for (UL a : G.back()) for (UL b : G[0]) ans.push_back({ a, b });
		cout << ans.size() << endl;
		rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
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
#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
int rcnt[200006];
int dp[200006];
set<P>S;

signed main() {
	string s; cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int l = s[i] - 'a';
		rcnt[i + 1] += 1 << l;
	}
	for (int i = 0; i <= n; i++) {
		rcnt[i + 1] ^= rcnt[i];
	}
	for(int i=1;i<=n;i++) {
		S.insert(P(rcnt[i], i));
	}
	queue<P>Q;
	fill(dp, dp + n + 1, 1e9);
	dp[0] = 0;
	Q.push(P(0, 0));
	while (!Q.empty()) {
		P np = Q.front(); Q.pop();
		int i = np.second;
		if (dp[i] < np.first)continue;

		int now = rcnt[i];
		vector<P>V;
		auto it = S.lower_bound(P(now, i));
		for (; it != S.end(); it++) {
			P p1 = *it;
			int e = it->second;
			if (it->first != now)break;
			if (dp[e] > dp[i] + 1) {
				dp[e] = dp[i] + 1;
				Q.push(P(dp[e], e));
				V.push_back(p1);
			}
		}
		rep(j, 26) {
			int now2 = now ^ (1 << j);
			it = S.lower_bound(P(now2, i));
			for (; it != S.end(); it++) {
				P p1 = *it;
				int e = it->second;
				if (it->first != now2)break;
				if (dp[e] > dp[i] + 1) {
					dp[e] = dp[i] + 1;
					Q.push(P(dp[e], e));
					V.push_back(p1);
				}
			}
		}
		rep(j, V.size()) {
			S.erase(S.find(V[j]));
		}
		//		M.erase(M.lower_bound(now));
	}
	cout << dp[n] << endl;
}

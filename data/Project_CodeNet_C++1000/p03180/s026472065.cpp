#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 17;
int N, a[mxN][mxN];
ll dp[1 << mxN], scores[1 << mxN];
vector<int> rem;

void rec(int idx, int mask, ll score, int grp) {
	if (idx == (int) rem.size()) {
		dp[mask] = max(dp[mask], score + scores[grp]);
		return;
	}
	rec(idx + 1, mask, score, grp);
	rec(idx + 1, mask ^ (1 << rem[idx]), score, grp ^ (1 << rem[idx]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	for (int mask = 0; mask < (1 << N); mask++) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if ((mask & (1 << i)) && (mask & (1 << j))) {
					scores[mask] += a[i][j];
				}
			}
		}
	}
	for (int mask = 0; mask < (1 << N); mask++) {
		rem.clear();
		for (int i = 0; i < N; i++) {
			if (!(mask & (1 << i))) {
				rem.push_back(i);
			}
		}
		rec(0, mask, dp[mask], 0);
	}
	cout << dp[(1 << N) - 1];
	
	return 0;
}

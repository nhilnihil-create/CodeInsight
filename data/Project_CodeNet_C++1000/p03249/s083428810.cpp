#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, A[1 << 17], dp[1 << 17]; vector<pair<long long, long long>> vec, G; vector<int> X[1 << 17];
long long dist[1 << 17], par[1 << 17], dp2[1 << 17];

void dfs(int pos, int dst) {
	dist[pos] = dst; dp2[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (dist[X[pos][i]] != -1) continue;
		par[X[pos][i]] = pos; dfs(X[pos][i], dst + 1);
		dp2[pos] += dp2[X[pos][i]];
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; vec.push_back(make_pair(A[i], i)); }
	sort(vec.begin(), vec.end());

	// 1 個正しい木を構築する
	for (int i = vec.size() - 1; i >= 0; i--) {
		int pos = vec[i].second;
		dp[pos] += 1;
		if (dp[pos] != N) {
			long long SA = A[pos] + (dp[pos] - (N - dp[pos]));
			int pos1 = lower_bound(vec.begin(), vec.end(), make_pair(SA, 0LL)) - vec.begin();
			pos1 = vec[pos1].second;
			dp[pos1] += dp[pos];
			G.push_back(make_pair(pos1, pos));
			X[pos1].push_back(pos); X[pos].push_back(pos1);
		}
	}

	// この木が正しいか判定する
	for (int i = 1; i <= N; i++) dist[i] = -1;
	dfs(1, 0);
	long long S = 0; for (int i = 1; i <= N; i++) { S += dist[i]; if (dist[i] == -1) S = (1LL << 60); }
	if (S != A[1]) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		long long SA = dp2[i] - (N - dp2[i]);
		if (A[i] + SA != A[par[i]]) {
			cout << "-1" << endl;
			return 0;
		}
	}

	for (int i = 0; i < G.size(); i++) { if (G[i].first > G[i].second) swap(G[i].first, G[i].second); }
	sort(G.begin(), G.end());
	for (int i = 0; i < G.size(); i++) cout << G[i].first << " " << G[i].second << endl;
	return 0;
}
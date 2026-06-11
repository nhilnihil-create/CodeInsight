#include "bits/stdc++.h"
using namespace std;
const long long INF = 1LL << 40;
int main() {
	long long N, K;
	cin >> N >> K;
	vector<vector<long long>>S(N);
	for (int i = 0;i<N;++i) {
		long long T, D;
		cin >> T >> D;
		--T;
		S[T].push_back(D);
	}
	vector<long long>maxlist;
	for (int i = 0;i<N;++i) {
		sort(S[i].begin(), S[i].end(), greater<long long>());
		if (0 != S[i].size()) {
			maxlist.push_back(S[i][0]);
		}
		else {
			maxlist.push_back(-INF);
		}
	}
	sort(maxlist.begin(), maxlist.end(), greater<long long>());

	//K種類選ぶ
	long long ans0 = 0;
	priority_queue<long long> que;
	for (int i = 0; i < K; ++i) {
		ans0 += maxlist[i];
	}	
	for (int i = K; i < N; ++i) {
		que.push(maxlist[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < S[i].size(); ++j) {
			que.push(S[i][j]);
		}
	}

	long long ans = ans0 + K*K;

	for (long long k = K - 1;k>=1;--k) {
		long long tmp = maxlist[k];
		long long tmp1 = que.top();
		if (tmp <tmp1) {
			que.pop();
			ans0 -= tmp;
			ans0 += tmp1;
			que.push(tmp);
		}
		ans = max(ans, ans0 + k * k);
	}
	cout << ans << endl;
	return 0;
}

#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	cin >> N;
	vector<pair<long long, long long> > D(N);
	vector<long long> E(N);
	vector<long long> COUNT(N, 1);
	vector<pair<long long, long long> > ANS;
	for (int i = 0; i < N; i++) cin >> D[i].first, D[i].second = i, E[i] = D[i].first;
	sort(D.begin(), D.end());
	sort(E.begin(), E.end());
	for (int i = N - 1; i > 0; i--) {
		long long C = COUNT[D[i].second];
		long long ND = D[i].first - (N - C * 2);
		long long it = lower_bound(E.begin(), E.end(), ND) - E.begin();
		if (D[it].first != ND || i <= it) {
			cout << -1 << endl;
			return 0;
		}
		ANS.push_back({ D[i].second, D[it].second });
		COUNT[D[it].second] += COUNT[D[i].second];
	}
	vector<vector<long long> > V(N);
	for (int i = 0; i < N - 1; i++) {
		V[ANS[i].first].push_back(ANS[i].second);
		V[ANS[i].second].push_back(ANS[i].first);
	}
	vector<long long> Dists(N, -1);
	Dists[D[0].second] = 0;
	queue<long long> Q;
	Q.push(D[0].second);
	while (!Q.empty()) {
		long long P = Q.front();
		Q.pop();
		for (long long NP : V[P]) {
			if (Dists[NP] == -1) {
				Dists[NP] = Dists[P] + 1;
				Q.push(NP);
			}
		}
	}
	long long SUM = 0;
	for (int i = 0; i < N; i++) SUM += Dists[i];
	if (SUM != D[0].first) cout << -1 << endl;
	else for (int i = 0; i < N - 1; i++) cout << ANS[i].first + 1 << " " << ANS[i].second + 1 << endl;
}
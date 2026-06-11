#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, Q, ANS = 1000000000;
	cin >> N >> K >> Q;
	vector<long long> A(N);
	vector<pair<long long, long long> > B(N);
	vector<bool> C(N, true);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = { A[i], i };
	}
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		vector<vector<long long> > V;
		V.clear();
		V.push_back(vector<long long>(0));
		for (int j = 0; j < N; j++) {
			if (C[j]) V[V.size() - 1].push_back(A[j]);
			else V.push_back(vector<long long>(0));
		}
		vector<long long> W;
		for (int j = 0; j < V.size(); j++) {
			if (V[j].size() < K) continue;
			sort(V[j].begin(), V[j].end());
			for (int k = 0; k < V[j].size() - K + 1; k++) {
				W.push_back(V[j][k]);
			}
		}
		sort(W.begin(), W.end());
		if (W.size() < Q) {
			break;
		}
		ANS = min(ANS, W[Q - 1] - W[0]);
		C[B[i].second] = false;
	}
	cout << ANS << endl;
}
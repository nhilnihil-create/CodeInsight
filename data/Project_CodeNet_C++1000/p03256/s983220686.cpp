#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M;
	string S;
	static long long COUNT[200000][2] = {};
	static vector<pair<long long, long long> > INPUT;
	static vector<long long> V[200000];
	static bool used[200000] = {};
	queue<long long> Q;
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		long long A, B;
		cin >> A >> B;
		A--, B--;
		if (A > B) swap(A, B);
		INPUT.push_back({ A, B });
	}
	sort(INPUT.begin(), INPUT.end());
	INPUT.erase(unique(INPUT.begin(), INPUT.end()), INPUT.end());
	for (int i = 0; i < INPUT.size(); i++) {
		long long A = INPUT[i].first, B = INPUT[i].second;
		if (A == B) {
			V[A].push_back(B);
			COUNT[A][S[B] - 'A']++;
		}
		else {
			V[A].push_back(B);
			V[B].push_back(A);
			COUNT[A][S[B] - 'A']++;
			COUNT[B][S[A] - 'A']++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (COUNT[i][0] == 0 || COUNT[i][1] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		long long P = Q.front();
		Q.pop();
		if (used[P]) continue;
		used[P] = true;
		for (long long NP : V[P]) {
			if (!used[NP]) {
				COUNT[NP][S[P] - 'A']--;
				if (COUNT[NP][S[P] - 'A'] == 0) Q.push(NP);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	static int T[100000] = {}, Par[100000] = {};
	static vector<int> V[100000];
	queue<int> Q;
	cin >> N >> M;
	for (int i = 0; i < N + M - 1; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		T[B]++;
		V[A].push_back(B);
	}
	for (int i = 0; i < N; i++) {
		if (T[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int P = Q.front();
		Q.pop();
		for (int NP : V[P]) {
			T[NP]--;
			if (T[NP] == 0) Q.push(NP), Par[NP] = P + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << Par[i] << endl;
	}
}
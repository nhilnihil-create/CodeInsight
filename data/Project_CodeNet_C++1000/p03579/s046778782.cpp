#include "bits/stdc++.h"
using namespace std;

long long N, M, Color[100000] = {};
vector<int> V[100000];

void init(int X) {
	for (int i = 0; i < X; i++) Color[i] = -1;
}

bool DFS(int X, int C) {
	Color[X] = C;
	for (int Y : V[X]) {
		if (Color[Y] == -1) {
			if (!DFS(Y, 1 - C)) return false;
		}
		else if (Color[Y] == Color[X]) return false;
	}
	return true;
}

int main() {
	cin >> N >> M;
	init(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	if (DFS(0, 0)) {
		long long Black = 0, White = 0;
		for (int i = 0; i < N; i++) {
			if (Color[i] == 0) Black++;
			else White++;
		}
		cout << Black * White - M;
	}
	else {
		cout << N * (N - 1) / 2 - M;
	}
}
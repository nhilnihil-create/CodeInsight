#include "bits/stdc++.h"
using namespace std;

#define INF 1145141919810364364

int N, M;
static vector<pair<int, long long> > V[100000];
static long long Num[100000];
bool check = true;

void DFS(int p) {
	for (pair<int, long long> x : V[p]) {
		if (Num[x.first] == INF) {
			Num[x.first] = Num[p] + x.second;
			DFS(x.first);
		}
		else {
			if (Num[x.first] != Num[p] + x.second) check = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int L, R, D;
		cin >> L >> R >> D;
		L--, R--;
		V[L].push_back({ R, D });
		V[R].push_back({ L, -D });
	}
	for (int i = 0; i < N; i++) {
		Num[i] = INF;
	}
	for (int i = 0; i < N; i++) {
		if (Num[i] == INF) {
			Num[i] = 0;
			DFS(i);
		}
	}
	if (check) cout << "Yes";
	else cout << "No";
}
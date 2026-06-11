#include "bits/stdc++.h"
using namespace std;

int N;
static vector<int> V[200000];
static int Dis[200000] = {};

void DFS(int v, int p, int d) {
	Dis[v] = d;
	for (int i : V[v]) {
		if (i != p) DFS(i, v, d + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	DFS(0, -1, 0);
	int MAX = 0, Far = 0;
	for (int i = 0; i < N; i++) {
		if (Dis[i] > MAX) {
			MAX = Dis[i];
			Far = i;
		}
	}
	for (int i = 0; i < N; i++) {
		Dis[i] = 0;
	}
	DFS(Far, -1, 0);
	MAX = 0;
	for (int i = 0; i < N; i++) {
		MAX = max(MAX, Dis[i]);
	}
	if (MAX % 3 == 1) cout << "Second";
	else cout << "First";
	return 0;
}
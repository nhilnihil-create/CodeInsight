#include <iostream>
#include <algorithm>
using namespace std;

long long N, X[100009], G[100009], bit[200009];

void add(int pos, int x) {
	while (pos <= 200008) { bit[pos] += x; pos += (pos&-pos); }
}
int sum(int pos) {
	int s = 0;
	while (pos >= 1) { s += bit[pos]; pos -= (pos&-pos); }
	return s;
}

long long solve(long long p) {
	G[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (X[i] <= p) G[i] = 1;
		else G[i] = -1;
	}
	for (int i = 1; i <= N; i++) G[i] += G[i - 1];
	for (int i = 0; i <= 200008; i++) bit[i] = 0;

	long long S = 0;
	for (int i = N; i >= 0; i--) {
		long long res = (N - i) - sum(G[i] + 100002); S += res;
		add(G[i] + 100002, 1);
	}
	return S;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i];

	long long L = 0, R = (1LL << 30), M, maxn = (1LL << 60);
	for (int i = 0; i < 40; i++) {
		M = (L + R) / 2;
		long long ret = solve(M);
		if (ret >= (N*(N + 1) / 2LL) / 2LL + 1LL) { maxn = min(maxn, M); R = M; }
		else { L = M; }
	}
	cout << maxn << endl;
	return 0;
}
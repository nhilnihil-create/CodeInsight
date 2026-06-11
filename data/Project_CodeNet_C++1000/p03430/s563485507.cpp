#include <bits/stdc++.h>
using namespace std;

char S[305];
int K;
int cache[305][305][305];

int LPS(int i, int j, int k) {
	if (~cache[i][j][k]) return cache[i][j][k];

	if (i == j) return cache[i][j][k] = 1;
	if (j - i == 1 && S[i] != S[j]) return cache[i][j][k] = k ? 2 : 1;
	if (j - i == 1 && S[i] == S[j]) return cache[i][j][k] = 2;
	if (S[i] != S[j]) {
		cache[i][j][k] = max(LPS(i+1, j, k), LPS(i, j-1, k));
		if (k) cache[i][j][k] = max(cache[i][j][k], LPS(i+1, j-1, k-1) + 2);
		return cache[i][j][k];
	}
	if (S[i] == S[j]) return cache[i][j][k] = LPS(i+1, j-1, k) + 2;
}

int main() {
	scanf("%s%d", S, &K);

	int len = strlen(S);

	for (int i = 0; i < 305; ++i) for (int j = 0; j < 305; ++j) for (int k = 0; k < 305; ++k) cache[i][j][k] = -1;

	printf("%d\n", LPS(0, len-1, K));
}
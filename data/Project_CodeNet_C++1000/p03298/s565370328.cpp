#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 38;

char S[N];
int n;
map<string, int> M[N];

int main() {

	scanf("%d%s", &n, S);
	For(i, 0, (1 << n) - 1) {
		char T[20];
		int l = 0, r = n;
		For(j, 0, n - 1) if (i & (1 << j)) T[l++] = S[j]; else T[--r] = S[j];
		T[n] = '\0';
		M[l][string(T)]++;
	}

	long long ans = 0;
	For(i, 0, (1 << n) - 1) {
		char T[20];
		int l = 0, r = n;
		For(j, 0, n - 1) if (i & (1 << j)) T[l++] = S[2 * n - 1 - j]; else T[--r] = S[2 * n - 1 - j];
		T[n] = '\0';
		ans += M[l][string(T)];
	}
	printf("%lld\n", ans);
	
	return 0;
}
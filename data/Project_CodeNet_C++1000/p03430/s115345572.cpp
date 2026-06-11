#include <stdio.h>
#include <algorithm>
using namespace std;

int D[303][303][155];
char S[303]; int K;

int main()
{
	scanf("%s %d", S+1,&K);
	int N = 0;
	while (S[N + 1]) N++;
	if (2 * K > N) {
		printf("%d\n" , N);
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > i; j--) {
			for (int k = 0; k <= K; k++) {
				D[i][j][k] = max(D[i - 1][j][k], D[i][j + 1][k]);
				if (S[i] == S[j]) D[i][j][k] = max(D[i][j][k], D[i - 1][j + 1][k] + 2);
				else {
					if (k) D[i][j][k] = max(D[i][j][k], D[i - 1][j + 1][k-1] + 2);
				}
			}
		}
	}

	int ans = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > i; j--) {
			for (int k = 0; k <= K; k++) {
				int d = D[i][j][k];
				if (i + 1 < j) d++;
				ans = max(ans, d);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
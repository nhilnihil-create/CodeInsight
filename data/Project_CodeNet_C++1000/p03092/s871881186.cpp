#include <stdio.h>

int N, A, B; long long D[5050];

int main()
{
	scanf ("%d %d %d", &N, &A, &B);
	for (int i = 1; i <= N; i++){
		int x; scanf ("%d", &x);
		long long X[5050];
		for (int j = 0; j <= N; j++) X[j] = 1e18;
		for (int j = 0; j <= N; j++){
			if (j <= x){
				if (X[x] > D[j]) X[x] = D[j];
				if (X[j] > D[j] + A) X[j] = D[j] + A;
			}
			else{
				if (X[j] > D[j] + B) X[j] = D[j] + B;
			}
		}
		for (int j = 0; j <= N; j++) D[j] = X[j];
	}

	long long ans = 1e18;
	for (int j = 0; j <= N; j++) if (ans > D[j]) ans = D[j];
	printf ("%lld\n", ans);

	return 0;
}
#include<cstdio>
const int MAXN = 3 * (1E5);
int a[MAXN + 5];
inline int min(int a, int b) {
	return a<b?a:b;
}
int main() {
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	if( A + B > N+1 || 1ll * A * B < N ) {
		printf("%d\n", -1);
		return 0;
	}
	for(int i=1;;i++) {
		int lim = min(i*B, N);
		for(int j=lim;j>(i-1)*B;j--)
			a[lim - j + (i-1)*B + 1] = j;
		if( lim == N ) break;
	}
	if( B == N ) {
		for(int i=1;i<N;i++)
			printf("%d ", a[i]);
		printf("%d ", a[N]);
		return 0;
	}
	for(int i=(N-1)/B+1;i>=1;i--) {
		int lim = min(i*B, N);
		if( N-(i-1)*B + (i-1) >= A ) {
			int cnt = A - (N - lim + (i-1));
			for(int j=1;j<=(i-1)*B;j++)
				printf("%d ", a[j]);
			for(int j=(i-1)*B+1;j<=lim-cnt;j++)
				printf("%d ", a[j]);
			for(int j=lim;j>=lim-cnt+1;j--)
				printf("%d ", a[j]);
			for(int j=lim+1;j<=N;j++)
				printf("%d ", j);
			break;
		}
	}
}
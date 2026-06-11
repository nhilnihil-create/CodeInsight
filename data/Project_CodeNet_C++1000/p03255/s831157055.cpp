#include<cstdio>

const int MAX_N = 200000;
int x[MAX_N];
long long sum_x[MAX_N+1];

int main() {
	long long N, X;
	scanf("%lld %lld", &N, &X);
	sum_x[0] = 0;
	for(int i=0;i<N;i++) {
		scanf("%d", &x[i]);
		sum_x[i+1] = sum_x[i] + x[i];
	}
	unsigned long long m = sum_x[N] * 5 + 2 * N * X;
	for(int k=1;k<=(N+1)/2;k++) {
		unsigned long long t = sum_x[N] + (k + N) * X;
		for(int i=0;i<=N/k;i++) {
			t += 2 * sum_x[N%k + i * k];
		}
		t += 2 * (sum_x[N] - sum_x[N - k]);
		if(m > t) m = t;
	}
	printf("%lld\n", m);
	return 0;
}

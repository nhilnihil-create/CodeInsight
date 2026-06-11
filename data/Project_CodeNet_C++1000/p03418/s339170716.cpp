#include<cstdio>

int main(){
	long long N, K;
	scanf("%lld %lld", &N, &K);
	if(!K){
		printf("%lld\n", N*N);
		return 0;
	}
	long long answer = 0;
	for (int b = K + 1; b <= N; ++b){
		int m = N/b;
		answer += m*(b - K);
		int remain = N % b - K + 1;
		if(remain >= 0)
			answer += remain;
	}
	printf("%lld\n", answer);
	return 0;
}
#include<cstdio>

long long N, X;
long long x[200010];

long long Solve(int groups){
	long long answer = 0;
	for (int i = 0; i < groups; ++i){
		answer += x[N - 1 - i];
		for (long long j = 0; N - 1 - i - groups*j >= 0; j++) answer += (j + 2)*(j + 2)*(N - 1 - i - groups*(j + 1) >= 0 ? x[N - 1 - i - groups*j] - x[N - 1 - i - groups*(j + 1)] : (x[N - 1 - i - groups*j]));
	}
	return answer;
}

int main(){
	scanf("%lld %lld", &N, &X);
	for (int i = 0; i < N; ++i) scanf("%lld", &x[i]);
	int ub = N, lb = 1;
	while(ub > lb){
		int mid = ub + lb + 1 >> 1;
		if(Solve(mid) <= Solve(mid + 1) + X) ub = mid - 1;
		else lb = mid;
	}
	long long min = Solve(lb) + X*(lb + N);
	if(lb < N && Solve(lb + 1) + X*(lb + 1 + N) < min)min = Solve(lb + 1) + X*(lb + 1 + N);
	if(lb > 1 && Solve(lb - 1) + X*(lb - 1 + N) < min)min = Solve(lb - 1) + X*(lb - 1 + N);
	printf("%lld\n", min);
	return 0;
}
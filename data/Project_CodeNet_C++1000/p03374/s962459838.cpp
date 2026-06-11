#include <cstdio>

int N;
long long C;
long long xi[100010];
long long vi[100010];
long long S1[100010], S2[100010];
long long N1[100010], N2[100010];
long long res;

void solve()
{
	int i;
	long long cur=0;
	for(i=1; i<=N; i++){
		cur += vi[i-1];
		S1[i] = S1[i-1];//
		if(cur-xi[i-1]>S1[i])
			S1[i] = cur-xi[i-1];
		S2[i] = S2[i-1];
		if(cur-xi[i-1]-xi[i-1]>S2[i])
			S2[i] = cur-xi[i-1]-xi[i-1];
	}
	long long tmp;
	cur = 0;
	for(i=N; i>=1; i--){
		cur += vi[i-1];
		tmp = C-xi[i-1];
		N1[i] = N1[i+1];
		if(cur-tmp>N1[i])
			N1[i] = cur-tmp;
		N2[i] = N2[i+1];
		if(cur-tmp-tmp>N2[i])
			N2[i] = cur-tmp-tmp;
	}
	res = S1[N];
	for(i=0; i<N; i++){
		if(S2[i]+N1[i+1] > res)
			res = S2[i]+N1[i+1];
	}
	for(i=N; i>0; i--){
		if(N2[i]+S1[i-1] > res)
			res = N2[i]+S1[i-1];
	}
	printf("%lld\n", res);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &N);
	scanf("%lld", &C);
	for(i=0; i<N; i++){
		scanf("%lld %lld", &xi[i], &vi[i]);
	}
	solve();
	return 0;
}
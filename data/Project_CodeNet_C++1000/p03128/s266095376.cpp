#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int d[] = {0, 2, 5, 5 ,4, 5, 6, 3, 7, 6};

int N, M, A[10], dp[MAXN], par[MAXN];
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &A[i]);
	sort(A, A + M);
	
	for(int i = 0; i <= N; i++){
		if(i == 0){
			dp[i] = 0;
			continue;
		}
		
		dp[i] = -1 << 20;
		for(int j = M - 1; j >= 0; j--)if(i >= d[A[j]]){
			if(1 + dp[i - d[A[j]]] > dp[i]){
				dp[i] = 1 + dp[i - d[A[j]]];
				par[i] = A[j];
			}
		}
	}
	
	while(N > 0){
		printf("%d", par[N]);
		N -= d[par[N]];
	}
	printf("\n");
	
	return 0;
}

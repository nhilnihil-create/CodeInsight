#include <bits/stdc++.h>
using namespace std;
bitset<4000010>dp;
int n,sum=0;
int main(){
	scanf("%d",&n);
	dp[0]=1;
	for(int i=1,w;i<=n;i++){
		scanf("%d",&w);
		sum+=w;
		dp|=(dp<<w);
	}
	for(int i=(sum+1)/2;i<=sum;i++) if(dp[i]){
		printf("%d\n",i);
		return 0;
	}
} 
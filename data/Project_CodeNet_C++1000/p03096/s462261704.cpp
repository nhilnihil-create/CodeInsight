#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int p=1e9+7;
int n, c[N];
int dp[N], t[N], nxt[N];
int main(){
	scanf("%d", &n); for(int i=1; i<=n; ++i){
		scanf("%d", &c[i]); if(t[c[i]])nxt[t[c[i]]]=i;
		t[c[i]]=i;
	}
	dp[1]=1;
	for(int i=1; i<=n; ++i){
		if(nxt[i]>i+1)(dp[nxt[i]]+=dp[i])%=p;
		(dp[i+1]+=dp[i])%=p;
	}
	printf("%d",dp[n]);
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,f[N],g[N],dp[1<<26];
char s[N];

void upd(int &x,int y){x=min(x,y);}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;++i){
		f[i]=f[i-1];
		f[i]^=1<<(s[i]-'a');
	}
	memset(dp,0x3f,sizeof dp); dp[0]=0;
	for (int i=1;i<=n;++i){
		g[i]=n;
		upd(g[i],dp[f[i]]+1);
		for (int j=0;j<26;++j){
			upd(g[i],dp[f[i]^(1<<j)]+1);
		}
		upd(dp[f[i]],g[i]);
	}
	printf("%d\n",g[n]);
	
	return 0;
}
			
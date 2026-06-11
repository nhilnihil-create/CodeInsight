#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=3007;
const ll mod=1e9+7;

ll dp[N],pre[N],suf[N];

int main(){
	int n=input();
	dp[1]=suf[1]=pre[1]=1;
	for(int i=2;i<=n;i++){
		char ch=getchar();
		if(ch=='<') for(int j=1;j<=i;j++) dp[j]=pre[j-1];
		else for(int j=1;j<=i;j++) dp[j]=suf[j];
		for(int j=1;j<=i;j++) pre[j]=(pre[j-1]+dp[j])%mod;
		for(int j=i;j>=1;j--) suf[j]=(suf[j+1]+dp[j])%mod;
	}
	printf("%lld\n",pre[n]);
}
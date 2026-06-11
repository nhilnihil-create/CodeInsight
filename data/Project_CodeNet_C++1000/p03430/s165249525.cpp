#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10ll+ch-'0';ch=getchar();}
	return x*f;
}
inline ll fast_pow(ll a,ll b,ll p){
    ll t=1;a%=p;
    while (b){
        if (b&1) t=t*a%p;
        b>>=1;a=a*a%p;
    }
    return t;
}
char s[10101];
int dp[303][303][303],n,K;
signed main(){
	scanf("%s",s+1);
	K=read();n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<=K;j++){
			dp[i][i][j]=1;
		}
	}
	for (int len=2;len<=n;len++){
		for (int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for (int k=0;k<=K;k++){
				dp[i][j][k]=max(dp[i][j-1][k],dp[i+1][j][k]);
				if (s[i]==s[j]) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k]+2);
				else if (k) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k-1]+2);
			}
		}
	}
	cout<<dp[1][n][K];
	return 0;
}

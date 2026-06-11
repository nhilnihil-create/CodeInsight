#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
int read(){
	int x=0,l=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*l;
}
using namespace std;
char s[200005]; int l,dp[1<<26],an,zt; bool fl[26];
int main(){
	scanf("%s",s+1); int n=strlen(s+1);
	memset(dp,127,sizeof(dp));
	zt=1<<(s[1]-97); dp[0]=0; dp[zt]=1;
	For(j,2,n){
		zt=zt^(1<<(s[j]-97));
		For(i,0,25){
			l=zt^(1<<i); dp[zt]=min(dp[zt],dp[l]+1);
		}
		if (j==n) an=dp[zt];
	}
	printf("%d\n",max(an,1));
	return 0;
}
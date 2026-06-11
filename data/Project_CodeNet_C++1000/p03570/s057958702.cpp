#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f
int dp[70000000];
char s[250000];
int f[250000];
int min(int a,int b){
	if (a>b) return b;else return a;
}
int main(){
	int n,i,x,ans,j;
	scanf("%s",s+1);
	s[0]='.';
	n=strlen(s)-1;
	memset(dp,inf,sizeof(dp));
	dp[0]=0;
	x=0;
	for (i=1;i<=n;i++) {
		x=x^(1<<(s[i]-'a'));
		ans=inf;
		for (j=1;j<=26;j++) 	ans=min(ans,dp[x^(1<<(j-1))]+1);
		dp[x]=min(dp[x],ans);
		f[i]=min(dp[x]+1,ans);
		
	}
	printf("%d\n",f[n]);
} 
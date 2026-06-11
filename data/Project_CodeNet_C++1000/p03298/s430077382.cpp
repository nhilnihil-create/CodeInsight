#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL n,ans=0,t[2][20],f[20][20],top[2];
char s[40];
void solve(LL S)
{
	//printf("S:%lld\n",S);
	top[0]=top[1]=0;
	for(LL i=0;i<n;i++)
	{
		LL c=S&(1<<i)?1:0;
		t[c][++top[c]]=i+1;
	}
	//printf("1:");for(int i=1;i<=top[0];i++) printf("%lld ",t[0][i]);printf("\n");
	//printf("2:");for(int i=1;i<=top[1];i++) printf("%lld ",t[1][i]);printf("\n");
	memset(f,0,sizeof(f));
	f[0][0]=1;
	//printf("ok\n");
	for(LL i=0;i<=top[0];i++)
		for(LL j=0;j<=top[1];j++)
		{
			if(i==top[0]&&j==top[1]) continue;
			LL k=2*n-i-j;
			if(i<top[0]&&s[t[0][i+1]]==s[k]) f[i+1][j]+=f[i][j];//printf("f:%lld %lld %lld %lld\n",i,j,i+1,j);
			if(j<top[1]&&s[t[1][j+1]]==s[k]) f[i][j+1]+=f[i][j];//printf("f:%lld %lld %lld %lld\n",i,j,i,j+1);
		}
	ans+=f[top[0]][top[1]];
	//printf("ans:%lld\n",ans);
}
int main()
{
	scanf("%lld",&n);scanf("%s",s+1);
	for(LL i=0;i<(1<<n);i++) solve(i);
	printf("%lld",ans);
}
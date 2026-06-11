#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1e9;
const int maxn=200100;
char str[maxn];
int dp[1<<26];
int zt[1<<26];
int n;
int main(){
//	freopen("D.in","r",stdin);
	scanf("%s",str+1);
	n=strlen(str+1);
	zt[0]=0;
	for(int i=1;i<=n;i++)
		zt[i]=zt[i-1]^(1<<(str[i]-'a'));
	for(int i=0;i<(1<<26);i++)
		dp[i]=INF;
	for(int i=0;i<26;i++)
		dp[1<<i]=0;
	dp[0]=0;
	int st;
	for(int i=1;i<=n;i++){
		st=dp[zt[i]]+1;
		for(int j=0;j<26;j++)
			if(st<dp[zt[i]^(1<<j)])
				dp[zt[i]^(1<<j)]=st;
		if(i==n) printf("%d\n",st);
	}
	return 0;
}

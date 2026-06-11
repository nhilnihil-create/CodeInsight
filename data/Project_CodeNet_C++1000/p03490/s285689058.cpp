#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool dp[N];
int x[N],y[N];
char s[N];
int xx,yy,sum=0,sum1=0;
int main()
{
	scanf("%s",s+1); scanf("%d%d",&xx,&yy);
	int n=strlen(s+1); int opt=0;
	int cntx=0; int cnty=0;
	for (int i=1;i<=n;i++){
		if (s[i]=='T'){
			if (!opt) x[++cntx]=sum;
			else y[++cnty]=sum;
			sum=0; opt=!opt;
		}
		else sum++;
	}
	if (s[n]!='T'){if (!opt) x[++cntx]=sum;else y[++cnty]=sum;}
	sum=0; sum1=0;
	for (int i=1;i<=cntx;i++) sum=sum+x[i];
	for (int i=1;i<=cnty;i++) sum1=sum1+y[i]; dp[x[1]]=true;
	for (int i=2;i<=cntx;i++)
		for (int j=sum;j>=x[i];j--) dp[j]=dp[j]|dp[j-x[i]];
	if (!dp[(sum+xx)/2]||(sum+xx)%2==1){puts("No");return 0;}
	memset(dp,false,sizeof(dp)); dp[0]=true;
	for (int i=1;i<=cnty;i++)
		for (int j=sum1;j>=y[i];j--) dp[j]=dp[j]|dp[j-y[i]];
	if (!dp[(yy+sum1)/2]||(sum1+yy)%2==1){puts("No");return 0;}
	puts("Yes");
	return 0;
}
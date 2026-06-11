#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
char ch[210000];
int a[210000],b[210000],bin[30],i,j,ans[210000],minn[68000000],n;
int main()
{
	scanf("%s",ch);
	n=strlen(ch);
	for (i=1;i<=n;i++)
	{
		a[i]=ch[i-1]-'a'+1;
	}
	bin[1]=1;
	for (i=2;i<=26;i++)  bin[i]=bin[i-1]<<1;
	for (i=1;i<=n;i++) b[i]=b[i-1]^bin[a[i]];
	memset(minn,0x7f,sizeof(minn));
	memset(ans,0x7f,sizeof(ans));
	minn[0]=0;
	for (i=1;i<=n;i++)
	{
		ans[i]=min(ans[i],minn[b[i]]+1);
		for (j=1;j<=26;j++)
		{
			ans[i]=min(ans[i],minn[b[i]^bin[j]]+1);
		}
		minn[b[i]]=min(minn[b[i]],ans[i]);
	}
	printf("%d\n",ans[n]);
	return 0;
}
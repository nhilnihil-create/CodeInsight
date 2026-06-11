#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f[202100],sum[70707070];
char a[202002];
int main()
{
	int n,tmp,i,j;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	tmp=0;
	sum[0]=1;
	for(i=1;i<=n;i++)
	{
		tmp=tmp^(1<<(a[i]-'a'));
		if(sum[tmp]!=0)
			f[i]=sum[tmp]+1;
		else
			f[i]=n+1;
		for(j=0;j<=25;j++)
		{
			if(sum[tmp^(1<<j)]!=0&&sum[tmp^(1<<j)]+1<f[i])
				f[i]=sum[tmp^(1<<j)]+1;
			//printf("%d\n",tmp^(1<<j));
			//f[i]=max(f[i],sum[tmp^(1<<j)]+1);
		}
		//printf("%d %d\n",i,f[i]);
		if(sum[tmp]==0||f[i]<sum[tmp])
			sum[tmp]=f[i];
		//sum[tmp]=min(sum[tmp],f[i]);
	}
	printf("%d",f[n]-1);
	return 0;
}

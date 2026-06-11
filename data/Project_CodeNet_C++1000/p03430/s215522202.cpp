#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char buf[310];
int n,k;
int mx[310][310][310];
int ans;
int main()
{
	scanf("%s%d",buf,&k);
	n=strlen(buf);
	ans=1;
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i+l-1<n;i++)
		{
			int j=i+l-1;
			if(l==1)mx[i][j][0]=1;
			else
			{
				for(int t=0;t<=k;t++)
				{
					mx[i][j][t]=max(mx[i+1][j][t],mx[i][j-1][t]);
					if(buf[i]==buf[j])
					{
						mx[i][j][t]=max(mx[i][j][t],mx[i+1][j-1][t]+2);
					}
					else
					{
						if(t)mx[i][j][t]=max(mx[i][j][t],mx[i+1][j-1][t-1]+2);
					}
					ans=max(ans,mx[i][j][t]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
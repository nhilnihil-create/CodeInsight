#include<bits/stdc++.h>
using namespace std;
int D,G;
int p[15],c[15];
int cnt;
int f[15][1005];

int main()
{
	scanf("%d%d",&D,&G);
	for(int i=1;i<=D;++i)
	   scanf("%d%d",&p[i],&c[i]),cnt+=p[i];
	for(int i=1;i<=D;++i)
		for(int j=0;j<=cnt;++j)
			for(int k=0;k<=p[i]&&k<=j;++k)
				f[i][j]=max(f[i][j],f[i-1][j-k]+k*i + (k==p[i]?c[i]/100:0));
	int ans;
	for(int i=0;i<=cnt;++i)
    {
    	f[D][i]*=100;
    	//cout<<f[D][i]<<endl;
    	ans=i;
    	if(f[D][i] >= G) break;
	}
	printf("%d\n",ans);
	return 0;
}
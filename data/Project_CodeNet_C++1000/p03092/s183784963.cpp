#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
int n,A,B;
LL ans;
const int N=5010;
LL f[N],p[N];
int main()
{
	cin>>n>>A>>B;memset(f,0x3f,sizeof(f));ans=f[0];f[0]=0;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		for(int j=0;j<=n;++j)
			if(!j)p[j]=f[j];
			else p[j]=min(p[j-1],f[j]);
		for(int j=0;j<=x;++j)f[j]+=A;
		for(int j=x+1;j<=n;++j)f[j]+=B;
		f[x]=min(f[x],p[x]);
	}
	for(int i=0;i<=n;++i)ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}
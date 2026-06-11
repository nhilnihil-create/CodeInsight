#include<bits/stdc++.h>
using namespace std;
#define MN 100001
int a[MN+5],s[MN+5],S[MN*3+5];
inline void add(int x){for(;x<=3*MN;x+=x&-x)++S[x];}
inline int sum(int x){int r=0;for(;x;x-=x&-x)r+=S[x];return r;}
int main()
{
	int n,i,l,r,mid,ans;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(l=1,r=1e9;l<=r;)
	{
		mid=l+r>>1;
		long long ss=0;
		memset(S,0,sizeof(S));add(MN);
		for(i=1;i<=n;++i)s[i]=s[i-1]+2*(a[i]<=mid)-1,ss+=sum(s[i]+MN-1),add(s[i]+MN);
		if(ss>=1LL*n*(n+1)/4+1)ans=mid,r=mid-1;else l=mid+1;
	}
	printf("%d",ans);
}
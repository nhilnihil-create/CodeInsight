#include<bits/stdc++.h>
using namespace std; 
#define N 100005
int n,ans,a[N],bit[N*4],s[N];
void add(int x){for(;x<N*4;x+=x&-x)bit[x]++;}
int qry(int x){int res=0;for(;x;x-=x&-x)res+=bit[x];return res;}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int l=0,r=1e9;l<=r;)
	{
		memset(bit,0,sizeof(bit));
		int mid=l+r>>1;long long res=0;
		add(n+1);
		for(int i=0;i<n;i++)
		{
			s[i]=(i?s[i-1]:0)+(a[i]>=mid?1:-1);
			res+=qry(s[i]+n+1);add(s[i]+n+1);
		}
		if(res>=1ll*n*(n+1)/2-res)ans=mid,l=mid+1;else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
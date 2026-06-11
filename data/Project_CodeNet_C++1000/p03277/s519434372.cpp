#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5+1;
int n,a[N],pre[N];
int	bit[2*N];
void update(int x)	{for(int i=x;i<2*N;i+=i&-i)	bit[i]++;	}
int find(int x)		{int res=0;for(int i=x;i>0;i-=i&-i)	res+=bit[i];return res;	}
bool check(int med)
{
	int i;pre[0]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=med)	pre[i]=pre[i-1]+1;
		else			pre[i]=pre[i-1]-1;
	}
	for(i=0;i<2*N;i++)	bit[i]=0;
	ll cnt=0ll;
	for(i=0;i<=n;i++)
	{
		cnt += (ll)find(pre[i]+N);
		update(pre[i]+N);
	}
	if(cnt>=1ll*n*(n+1)/4)		return true;
	return false;
}
int main()
{
	int i,l=1,r=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r=max(r,a[i]);
	}
	int ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		bool e = check(mid);
		if(e==true)
		{
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	printf("%d",ans);
}
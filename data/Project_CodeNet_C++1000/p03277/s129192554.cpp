#include<bits/stdc++.h>
using namespace std;
const int N=300010,lim=3e5,base=1e5+5;
int s[N],n,a[N],sum[N];
int lowbit(int k){return k&-k;}
void add(int x){for(int i=x;i<=lim;i+=lowbit(i))s[i]++;}
int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=s[i];return res;}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		if(a[i]<x)
			sum[i]=sum[i-1]+1;
		else
			sum[i]=sum[i-1]-1;
	for(int i=1;i<=lim;i++)
		s[i]=0;
	long long res=0;
	add(base);
	for(int i=1;i<=n;i++)
	{
		res+=query(sum[i]+base-1);
		add(sum[i]+base);
	}
	return res<(1ll*n*(n+1)/2)/2+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=1e9,res=0,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))res=mid,l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}

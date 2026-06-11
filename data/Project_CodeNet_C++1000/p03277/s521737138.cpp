#include<cstdio>
#include<cstring>
using namespace std;
int N,Pre[100005],a[100005];
long long A[100005],l=0,m,r=1e9+1,F[800005],cnt;
void in(int O,int l,int r,int k)
{
	if(l==r)
	{
		F[O]++;
		return ;
	}
	int mid=(l+r)/2;
	if(k<=mid)
	in(O*2,l,mid,k);
	else
	in(O*2+1,mid+1,r,k);
	F[O]=F[O*2]+F[O*2+1];
}
long long qu(int O,int l,int r,int s,int t)
{
	if(l==s&&r==t)
	return F[O];
	int mid=(l+r)/2;
	if(t<=mid)
	return qu(O*2,l,mid,s,t);
	if(s>mid)
	return qu(O*2+1,mid+1,r,s,t);
	return qu(O*2,l,mid,s,mid)+qu(O*2+1,mid+1,r,mid+1,t);
}
bool check()
{
	cnt=0;
	memset(F,0,sizeof(F));
	for(int i=1;i<=N;i++)
	if(A[i]>=m)
	a[i]=1;
	else
	a[i]=-1;
	for(int i=1;i<=N;i++)
	Pre[i]=Pre[i-1]+a[i];
	in(1,0,N*2,N);
	for(int i=1;i<=N;i++)
	{
		cnt+=qu(1,0,N*2,0,Pre[i]+N);
		in(1,0,N*2,Pre[i]+N);
	}
	if(cnt*2>=(long long)N*(N+1)/2)
	return true;
	return false;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	scanf("%lld",&A[i]);
	while(l+1<r)
	{
		m=(l+r)/2;
		if(check())
		l=m;
		else
		r=m;
	}
	printf("%lld",l);
	return 0;
}
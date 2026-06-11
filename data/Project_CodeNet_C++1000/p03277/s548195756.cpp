#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100011;
int n,a[N],r=0,l=0,ans=0;
int c[N*10],s[N<<1];
void add(int x)
{
	while(x<=N*2)
	  c[x]++,x+=x&(-x);
}
ll ask(int x)
{
	ll ans=0;
	while(x)
	{
		ans+=c[x];
		x-=x&(-x);
	}
	return ans;
}
bool check(int x)
{
	for(int i=1;i<=2*N;i++) c[i]=0;
	s[0]=0;
	for(int i=1;i<=n;i++)
	  s[i]=s[i-1]+(a[i]>=x?1:-1);
	ll sum=0;
	for(int i=0;i<=n;i++)
    {
       sum+=ask(s[i]+N);
       add(s[i]+N);
	} 
	return sum>=(ll)n*(n+1)/4;
}
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]),r=max(r,a[i]);
  while(l<=r)
  {
  	int mid=(l+r)>>1;
  	if(check(mid)) 
	  l=mid+1;
	else r=mid-1;
  }
  printf("%d\n",r);
  return 0;
}

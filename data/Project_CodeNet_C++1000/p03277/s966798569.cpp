#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100011;
int n,a[N],r=0,l=0,ans=0;
int c[N*10],s[N<<1];
int cc[N*10],d[N*10],tot=0;
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
//求中位数小于等于x的区间数至少为n*(n+1)/2/2+1的最小的x
bool check(int x)
{
	for(int i=1;i<=2*N;i++) c[i]=0;
	s[0]=0;
	for(int i=1;i<=n;i++)
	  s[i]=s[i-1]+(a[i]<=x?1:-1);
	ll sum=0;
	for(int i=0;i<=n;i++)
    {
       sum+=ask(s[i]-1+N);
       add(s[i]+N);
	}  
//	cout<<x<<" "<<sum<<endl;
	return sum>=(((ll)n*(n+1)/2/2)+1);
}
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
  scanf("%d",&n);  l=987654321;
  for(int i=1;i<=n;i++) scanf("%d",&a[i]),r=max(r,a[i]),l=min(l,a[i]);
//  for(int i=1;i<=n;i++)
//    for(int j=i;j<=n;j++)
//	  {
//	  	for(int z=1;z<=j-i+1;z++)
//	  	  cc[z]=a[i+z-1];
//	  	sort(cc+1,cc+j-i+2);
//	  	d[++tot]=cc[(j-i+1)/2+1];
//	  } 
//  sort(d+1,d+tot+1);
//  for(int i=1;i<=tot;i++) 
//    cout<<d[i]<<" ";
//  cout<<"---------"<<endl; 
//  cout<<d[tot/2+1]<<endl;
// 
//  for(int i=l;i<=r;i++)
//    check(i);
  while(l+1<=r)
  {
	int mid=(l+r)>>1;
  	if(check(mid)) 
	  r=mid;
	else l=mid+1;
  }
  printf("%d\n",r);
  return 0;
}

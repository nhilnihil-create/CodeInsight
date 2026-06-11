#include<iostream>
#include<algorithm>
using namespace std;
struct X
{
  long long p,v;
}a[100010];
bool cmp(X x,X y)
{
 return x.p<y.p;
}
int main() 
{
 long long ans,c,aa[100010],bb[100010];
 int n,i,j,k;
 cin>>n>>c;
 for (i=1;i<=n;i++)
  scanf("%lld %lld",&a[i].p,&a[i].v);
 sort(a+1,a+n+1,cmp);
 aa[0]=0;
 for (i=1;i<=n;i++)
  aa[i]=aa[i-1]+a[i].v-a[i].p+a[i-1].p;
 a[n+1].p=c;
 bb[n+1]=0;
 for (i=n;i>=1;i--)
  bb[i]=bb[i+1]+a[i].v-a[i+1].p+a[i].p;
 for (i=2;i<=n;i++)
  aa[i]=max(aa[i-1],aa[i]);
 for (i=n-1;i>=1;i--)
  bb[i]=max(bb[i+1],bb[i]);  
 ans=0;
 for (i=1;i<=n;i++)
 {
  ans=max(ans,-a[i].p+aa[i]+bb[i+1]);
  ans=max(ans,a[i].p-c+bb[i]+aa[i-1]);
  ans=max(ans,aa[i]);
  ans=max(ans,bb[i]); 
 } 
 cout<<ans<<endl;
 return 0;   
}
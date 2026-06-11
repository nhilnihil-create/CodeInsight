#include <cstdio>

using namespace std;

long long ans;

int n,suma,sumb,a[10000010];

int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  int l=1,r=0;
  while(l<=n)
  {
    while((suma^a[r+1])==(sumb+a[r+1])&&r<n)
    {
      suma^=a[r+1];
      sumb+=a[r+1];
      r++;
    }
    ans=ans+(r-l+1);
    suma=suma^a[l];
    sumb=sumb-a[l];
    l++;
  }
  printf("%lld",ans);
}

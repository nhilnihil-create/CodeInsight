#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+3;
int a[N];
int32_t main()
{
  #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
  #endif
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];

  int ans=0;
  for(int i=1;i<=n+1;i++)
    ans+=abs(a[i]-a[i-1]);

  for(int i=1;i<=n;i++)
  {
    int tmp=abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
    int add=abs(a[i-1]-a[i+1]);
    ans+=add;
    ans-=tmp;
    cout<<ans<<"\n";
    ans+=tmp;
    ans-=add;
  }
  


 

}
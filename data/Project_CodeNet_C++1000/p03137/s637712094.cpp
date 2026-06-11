#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif


  int n,k;
  cin>>n>>k;
  vector<int> x(k);
  for(int &i:x)cin>>i;
  if(k==1){cout<<0;return 0;}
  sort(x.begin(),x.end());
  vector<int> diff(k-1);
  for(int i=1;i<k;i++)diff[i-1]=abs(x[i]-x[i-1]);

  int ans=0;
  sort(diff.begin(),diff.end());
 
for(int i=0;i<(k-n);i++)ans+=diff[i];
  cout<<ans;
}
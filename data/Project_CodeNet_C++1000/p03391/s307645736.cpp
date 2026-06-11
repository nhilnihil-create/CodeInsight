#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

  int n;
  cin>>n;
  int mx=0;
  int a[n+1],b[n+1];
  int tot=0;
  bool flag=false;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i]>>b[i];
    if(a[i]!=b[i])
      flag=true;
    tot+=a[i];
  }
  if(!flag)
  {
    cout<<0;
    return 0;
  }
  for(int i=1;i<=n;i++)
  {
    if(a[i]>b[i])
    {
      mx=max(mx,tot-a[i]+a[i]-b[i]);
    }
  }
  cout<<mx;

}
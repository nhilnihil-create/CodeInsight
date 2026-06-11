#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int sz=(1<<18)+5;
multiset<int>s[sz];
int a[sz];

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
  for(int i=0;i<(1<<n);i++)
  {
    cin>>a[i];
    s[i].insert(a[i]);
  }
  int lim=(1<<n);
  for(int i=0;i<n;i++)
  {
    for(int mask=0;mask<lim;mask++)
    {
      if(mask&(1<<i))
      {
        for(auto j:s[mask^(1<<i)])
          s[mask].insert(j);
        while(s[mask].size()>2)
          s[mask].erase(s[mask].begin());
      }
    }
  }
  int mx=0;
  for(int i=1;i<lim;i++)
  {
    int ans=0;
    for(auto j:s[i])
      ans+=j;
    mx=max(mx,ans);
    cout<<mx<<'\n';
  }

}
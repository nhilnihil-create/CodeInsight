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

  int n,k,q;
  cin>>n>>k>>q;
  int a[n+2]={0};
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  int res=1e17;
  for(int i=1;i<=n;i++)
  {
    int mm=a[i];
    vector<vector<int> >temp;
    vector<int>z;
    for(int j=1;j<=n+1;j++)
    {
      if(a[j]>=mm)
      {
        z.push_back(a[j]);
      }
      else
      {
        if(z.size()>0)
        {
          temp.push_back(z);
          z.clear();
        }
      }
    }

    int l=a[i],r=1e9;
    int mn=1e10;
    while(l<=r)
    {
      int mid=l+(r-l)/2;
      int cnt=0;
      for(auto t:temp)
      {
        int tot=t.size();
        int count=0;
        for(auto j:t)
        {
          count+=(j>mid);
        }
        if(tot>=k)
        {
          tot-=k-1;
          count-=min(count,k-1);
          cnt+=(tot-count);
        }
      }
      if(cnt>=q)
      {
        mn=min(mn,mid);
        r=mid-1;
      }
      else
      {
        l=mid+1;
      }
    }
    if(mn!=1e10)
    {
      res=min(res,mn-a[i]);
    }
  }
  cout<<res;

}
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int sz=(1<<16)+5;
int dp[sz];
vector<int>vec[sz];
int a[17][17];

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

// -------------------------------------Code starts here---------------------------------------------------------------------     

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  int lim=(1<<n)-1;
  for(int i=0;i<=lim;i++)
    for(int j=0;j<n;j++)
      for(int k=j+1;k<n;k++)
        if(((1<<j)&i)&&(i&(1<<k)))
          dp[i]+=a[j][k];

  for(int mask=0;mask<=lim;mask++)
  {
    for(int j=mask;j>0;j=((j-1)&mask))
    {
      vec[mask].push_back(j);
    }
  }

  for(int mask=0;mask<=lim;mask++)
  {
    for(auto j:vec[mask])
    {
      dp[mask]=max(dp[mask],dp[j]+dp[j^mask]);
    }
  }
  cout<<dp[lim];

// -------------------------------------Code ends here------------------------------------------------------------------
    clock_t clk;
  clk = clock();

    clk = clock() - clk;
  cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
  return 0;
}

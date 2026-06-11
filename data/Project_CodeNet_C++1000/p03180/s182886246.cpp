    //#include <ext/pb_ds/assoc_container.hpp> 
    // #include <ext/pb_ds/tree_policy.hpp> 
    #include <iostream>
    #include <iomanip>
    #include <sstream>
    #include <cstring>
    #include <vector>
    #include <deque>
    #include <queue>
    #include <set>
    #include <map>
    #include <valarray>
    #include <iterator>
    #include <functional>
    #include <limits>
    #include <algorithm>
    #include <numeric>
    #include <cmath>
    #include <cassert>
    #include <unordered_map>
    #include <unordered_set>
    #include <stack>
    using namespace std;
    #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define trace(x) cerr << #x << ": " << x << " " << endl;
     
    typedef int64_t ll;
     
    #define endl '\n'
    #define int ll
    ll mod=1e9+7;
    ll mod1=1e9+5;
     
    ll power(ll a,ll b)
    {
        if(b==0) return 1;
        else if(b%2==0)
            return power((((a%mod)*(a%mod))%mod),b/2)%mod;
        else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
    }
     
    // using namespace __gnu_pbds;
    // #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
    //find_by_order(k)  returns iterator to kth element starting from 0;
    //order_of_key(k) returns count of elements strictly smaller than k;
    //erase,insert same as normal set
    
    int32_t main()
    {
        IOS

      int n;
      cin>>n;
      int a[n][n];
      for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];

    int dp[(1ll<<n)];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<(1ll<<n);++i) 
    {
        int cost=0;
        for(int j=0;j<n;++j)
        {
            if(i&(1ll<<j))
                for(int k=j+1;k<n;++k)
                {
                    if(i&(1ll<<k))
                        cost+=a[j][k];
                }
        }
        dp[i]=cost;
    }  
    int x[(1ll<<n)];
    memset(x,0,sizeof(x));
    for(int i=0;i<(1ll<<n);++i)
    {
        for(int j=i;j>=0;j=(j-1)&i)
        {
            int pr=i^j;
            x[i]=max(x[i],x[j]+dp[pr]);
            if(j==0)
                break;
        }
    }
    // for(int i=0;i<1ll<<n;++i)
    //     cout<<x[i]<<" ";

    cout<<x[(1ll<<n)-1];


     

    }       
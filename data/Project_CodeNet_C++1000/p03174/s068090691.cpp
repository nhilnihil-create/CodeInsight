    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    using namespace std;
    int pairs[22][22];
    ll dp[1<<22];
    ll solve(int mask,int men, int n)
    {
       // cout<<men<<" "<<mask<<"\n";
        if(men > n)
            return 0;
        if(mask== (1<<n)-1)
            return 1;
        if(dp[mask]!=-1)
            return dp[mask];

        ll ans =0;
        for(int i=0; i<n; i++)
        {
            if(pairs[men][i]==1 && !(mask & (1<<i)))
            {
                ans= ((ans%M)+(solve((mask | (1<<i)),men+1, n)%M))%M;

            }
        }
        //cout<<men<<" "<<ans<<"\n";
        return dp[mask]=ans;
    }
    int main()
    {

        ios_base::sync_with_stdio(false);
    	cin.tie(NULL);

      int  n;
      cin>>n;
      for(int i=0; i<n; i++)
      {

          for(int j=0; j<n; j++)
          {

              cin>>pairs[i][j];
          }
      }
      int mask=0;
      memset(dp,-1,sizeof(dp));
      cout<<(solve(mask,0,n)%M);
        return 0;

    }

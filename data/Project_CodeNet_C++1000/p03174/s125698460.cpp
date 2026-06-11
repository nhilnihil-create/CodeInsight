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
    #define fast   ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
    using namespace std;
    ll graph[22][22];
    ll dp[22][1<<22];
    ll dfs(int i, int n, int mask)
    {
        if(i>n)
            return 0;
        if(mask == (1<<n)-1)
            return 1;

        if(dp[i][mask]!=-1)
            return dp[i][mask];
        ll ans =0;
        for(int j=0; j<n; j++)
        {
            if(graph[i][j]==1 && !(mask & (1<<j)))
            {
                ans = (ans + dfs(i+1, n, (mask | 1<<j)))%M;
            }
        }
        //cout<<i<<" "<<mask<<" "<<ans<<"\n";
        return dp[i][mask] = ans%M;
    }
    int main()
    {
            fast
         int n;
         cin>>n;
         for(int i=0; i<n; i++)
         {
             for(int j=0; j<n; j++)
             {
                 cin>>graph[i][j];
             }
         }
         int mask=0;
         memset(dp,-1,sizeof(dp));
         cout<<dfs(0,n,mask);

        return 0;

    }


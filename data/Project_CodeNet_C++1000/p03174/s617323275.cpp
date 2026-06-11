/* ****VIKRAM ADITYA**** */
#include<bits/stdc++.h>

#define ll          int
#define F           first
#define S           second
#define pb          push_back
#define mp          make_pair
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define ld             long double
#define hell        1000000007
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;


// vector<vector<ll>> dp(n,vector<ll>(n00000,-1));
// ll dfs(ll wom ,ll mask, ll &n )
// {
//     if(wom>=n)
//         return 0;

    
//     // if(mask==(1<<n)-1)
//     //     return 1;
//     if(dp[wom][mask]!=-1)
//         return dp[wom][mask];
    
//     ll ans=0;
//         for (int i = 0; i <n; ++i)
//         {
//             if(((mask & (1<<i))==1) && (v[wom][i]==1))
//                 ans=(ans+dfs(wom+1,(mask &(0<<i)), n))%hell;
//         }
//         return dp[wom][mask]=ans;
        
    

// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll v[n][n];
        for (int i = 0; i < n; ++i)
        {
            /* code */
            for (int j = 0; j < n; ++j)
            {
                cin>>v[i][j];
                // v[i].pb(r);
            }

        }



        // ll mask;
       
            ll mask=(1<<n)-1;
        
        
         ll dp[1<<n];
         memset(dp,0,sizeof(dp));
         dp[0]=1;
        // memset()
        for (int i = 0; i <=(1<<n)-2 ; ++i)
        {
        	
        	ll x=__builtin_popcount(i);
        	for (int j = 0; j < n; ++j)
        	{
        		if(v[x][j] && ((i&(1<<j))==0)) dp[i|((1<<j))]=(dp[i|((1<<j))]+dp[i])%hell;
        	}
        }

        cout<<dp[(1<<n) -1];
    }

    
    time
    return 0;
} 
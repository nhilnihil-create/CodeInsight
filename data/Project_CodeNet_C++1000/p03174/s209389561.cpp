/* ****Ragnar7 _Lawliet_**** */
/* First, solve the problem.Then write the code. */
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

//vector use mat kiya kr
const ll N = 21;
ll dp[N][1<<N];

ll dfs(ll wom ,ll mask, ll n , vector<vector<ll>> &v)
{
    if(wom>=n)
    {
        //suhagraat ka din sab set xD
        if(mask==0)
            return 1;
        return 0;
    }
    if(dp[wom][mask]!=-1)
        return dp[wom][mask];
    ll ans=0;
    for (int i = 0; i <n; ++i)
    {
        if(((mask & (1<<i))) && (v[wom][i]==1))
            ans=(ans+dfs(wom+1,(mask-(1<<i)), n, v))%hell;

    }
    dp[wom][mask]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);
    #endif
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>> v(n,vector<ll> (n,0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin>>v[i][j];
            }

        }
       
        ll mask=(1<<n)-1;
        memset(dp,-1,sizeof(dp));
        ll ans=dfs(0,mask, n , v);

        cout<<ans;
    }

    
    time
    return 0;
} 
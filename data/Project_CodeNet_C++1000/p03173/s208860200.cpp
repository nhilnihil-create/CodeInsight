
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;


#define LETS_GET_SCHWIFTY ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
#define ff              first
#define ss              second
#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define vpii            vector<pair<int,int> >
#define all(x)          x.begin(),x.end()
#define matrixprint(arr,a,b,c,d) for(int i=a;i<=c;i++){for(int j=b;j<=d;j++){cout<<arr[i][j]<<" ";}cout<<"\n";}
#define show(arr,x,y)   for(int i=x;i<=y;i++){cout<<arr[i]<<" ";}cout<<"\n"
#define sz(x)           (int)x.size()
#define db(x)           cout<<x<<"\n";

const int N = 2e5 + 5;

#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define deb(...)
#endif

	
//////////////////////////////code//////////////////////////////

void solve()
{
   // cout << "-------------------" << "\n";
    
    int n;
    cin>>n;
    
    vi arr(n+1);
    
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    int dp[n+1][n+1]={0},pre[n+1]={0};
    
    
    for(int i=1;i<=n;i++)  pre[i] = pre[i-1] + arr[i];
    
    for(int i=0;i<n;i++)
    dp[i][i] = 0;
    
    for(int len = 2;len <= n; len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j = i + len - 1;
            dp[i][j] = inf;
            
            for(int k = i+1; k<=j;k++)
            {
                dp[i][j] = min(dp[i][j] , dp[i][k-1] + dp[k][j] + pre[j]-pre[i-1]);
            }
        }
    }
    
    //matrixprint(dp,0,0,n,n);
    
    cout<<dp[1][n]<<"\n";
  
 

  //  cout << "-------------------" << "\n";

}

int32_t main()
{

    LETS_GET_SCHWIFTY;

    int t = 1;
   // cin >> t;

    while (t--)
        solve();

}

// check out for following mistakes-
// if using pb operation on vector and then trying to access index..check if sizeof that vec could remain 0 only
// is using prime sieve make sure it fits
// when using factorial template or combinatorics make sure that you edit fillfac fun values and array values

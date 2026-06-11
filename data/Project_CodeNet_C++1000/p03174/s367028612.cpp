// Author : Chi
// created : Thursday 2020-06-04
// Sawal : Practice

//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//macros
#define ll 		    long long
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb(x)       push_back(x)
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define TEST1       solve();
#define mod         1000000007
#define aLL(x)      x.begin(),x.end()
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define db(...)     __f(#__VA_ARGS__, __VA_ARGS__)                      //for debugging
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
//LOVE ALGO
int a[401][401];
int dp[21][1<<22];
int n;
int rec(int r,int w){
    if(r==n)
        return 1;
    if(dp[r][w]!=-1)
        return dp[r][w];
    int ans=0;
    for(int i=0;i<n;i++)
        if(((1<<i)&w) == 0&&a[r][i]==1)
            ans=(ans+rec(r+1,w|(1<<i)))%mod;
    return dp[r][w]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<rec(0,0);
    }
// Driver Code
int main(){
    CHI
    TEST1
    return 0;
}

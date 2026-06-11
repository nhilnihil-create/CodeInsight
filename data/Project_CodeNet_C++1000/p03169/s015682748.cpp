// Author : Chi
// created :
//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//macros
#define ll 		    long long
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb          push_back
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define TEST1       solve();
#define mod         1000000007
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
long double dp[301][301][301];
long double rec(int x,int y,int z,int n){
    if(x < 0 || y < 0 || z < 0)
        return 0;
    if(x==0 && y==0 && z==0)
        return 0;
    if(dp[x][y][z] >= -0.9)
        return dp[x][y][z];
    return (dp[x][y][z] = (long double)(n + x * rec(x-1,y,z,n) + y * rec(x+1,y-1,z,n) + z*rec(x,y+1,z-1,n))/(long double)(x+y+z));
}
void solve(){
    int n;
    cin>>n;
    memset(dp,-1.0,sizeof dp);
    int ct[4];
    memset(ct,0,sizeof ct);
    r1n(kk,n){
        int t;
        cin>>t;
        ct[t]++;
    }
    cout<<pdp(rec(ct[1],ct[2],ct[3],n),10);
}

// Driver Code
int main(){
    TEST1
    return 0;
}

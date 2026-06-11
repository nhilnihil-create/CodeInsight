//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int N = 2e7 + 7;
const int mod=1e9+7;
const int INF=1e18+7;
const int dx[] = {-1, 1, 0,  0}; // UDLR
const int dy[] = { 0, 0, -1, 1}; // UDLR
inline int maximum (int a,int b){
     if(a>b) return a;
     else return b;
}
inline int minimum (int a,int b){
    if(a>b) return b;
     else return a;
}
int32_t main (){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);cout.tie(NULL);

        int n; cin>>n; vector<int> h(n); vector<int>dp(n+1,INF);
        for(int i=1;i<=n;i++) cin>>h[i];
        dp[1]=0; dp[2]=abs(h[2]-h[1]);
        for(int i=3;i<=n;i++){
            dp[i]=minimum(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
        }
         cout<<dp[n];
 return 0;
 }

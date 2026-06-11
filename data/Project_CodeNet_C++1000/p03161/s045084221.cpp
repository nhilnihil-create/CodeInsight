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

        int n,k; cin>>n>>k; vector<int> h(n+1); vector<int> dp(n+1,INF);
        for(int i=1;i<=n;i++) cin>>h[i];
        dp[1]=0;
        for(int i=2;i<=n;i++){
          for(int j=i-k>=1?i-k:1;j<=i;j++){
            dp[i]=minimum(dp[j]+abs(h[i]-h[j]),dp[i]);
          }
        }
          cout<<dp[n];
 return 0;
 }

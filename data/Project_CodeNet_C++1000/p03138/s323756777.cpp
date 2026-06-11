#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define ld long double

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)

#define pii pair<int, int>
#define pll pair<ll, ll>

#define fi first
#define se second

#define pb push_back
#define eb emplace_back

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(), a.end()

#define endl '\n'
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const double PI=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

ll dp[50][2];
// 0なら一致，1ならsmaller 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  
  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;
  rep(i,50){
    ll bit = 1ll<<(49-i);
    
    int sum = 0;
    rep(i,n) if(a[i] & bit) sum++;
    
    ll val0=bit*sum;
    ll val1=bit*(n-sum);
    
    //小さいからの小さい
    if(dp[i][1] != -1){
      chmax(dp[i+1][1],dp[i][1]+max(val0,val1));
    }
    //一致からの小さい
    if(dp[i][0] != -1){
      if(k&bit){
        chmax(dp[i+1][1],dp[i][0]+val0);
      }
    }
    //一致からの一致
    if(dp[i][0] != -1){
      if(k&bit) chmax(dp[i+1][0],dp[i][0]+val1);
      else chmax(dp[i+1][0],dp[i][0]+val0);
    }
  }
  
  cout << max(dp[50][0],dp[50][1]) << endl;
      
      
    
    
  return 0;
}

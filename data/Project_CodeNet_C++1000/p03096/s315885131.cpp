#include<bits/stdc++.h>
#define endl '\n';
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<int> c(N);
  rep(i,N){
    cin >> c[i];
  }
  vector<vector<int>> places(200100);
  rep(i,N){
    places[c[i]].push_back(i);
  }
  vector<ll> dp(200100,0);
  dp[0] = 1;
  for(int i=1; i<=N; i++){
    dp[i] += dp[i-1];
    dp[i] %= mod;
    int color = c[i-1];
    int it = lower_bound(places[color].begin(),places[color].end(),i-1) - places[color].begin();
    if(it>0){
      int j = places[color][it-1];
      if((i-1)-j > 1){
        dp[i] += dp[j+1];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[N] << endl;
  return 0;
}
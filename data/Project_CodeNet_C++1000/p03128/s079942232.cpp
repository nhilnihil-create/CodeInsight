#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod2 = 1000000007;
constexpr ll mod = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
  string S = "255456376";
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  vector<string> dp(11000,"-");
  dp[0] = "";
  for(int i=0; i<=N; i++){
    if(dp[i] == "-") continue;
    for(int m: A){
      if(dp[i+S[m-1]-'0'] == "-"){
        dp[i+S[m-1]-'0'] = dp[i] + to_string(m);
      }else if(dp[i+S[m-1]-'0'].size() < dp[i].size()+1){
        dp[i+S[m-1]-'0'] = dp[i] + to_string(m);
      }else if(dp[i+S[m-1]-'0'] < dp[i]+to_string(m)){
        dp[i+S[m-1]-'0'] = dp[i] + to_string(m);
      }
    }
  }
  cout << dp[N] << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

ll dp[100010][4];

void f(ll &a, ll b){
  if(b>=MOD)b-=MOD;
  a += b;
  if(a>=MOD)a-=MOD;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  string s;
  cin >> s;
  
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  
  int n = s.size();
  rep(i,n){
    rep(j,4){
      if(s[i]=='?')f(dp[i+1][j],3*dp[i][j]);
      else f(dp[i+1][j],dp[i][j]);
    }
    if(s[i]=='A' || s[i]=='?') f(dp[i+1][1],dp[i][0]);
    if(s[i]=='B' || s[i]=='?') f(dp[i+1][2],dp[i][1]);
    if(s[i]=='C' || s[i]=='?') f(dp[i+1][3],dp[i][2]);
  }
  
  cout << dp[n][3] << endl;
    
  return 0;
}

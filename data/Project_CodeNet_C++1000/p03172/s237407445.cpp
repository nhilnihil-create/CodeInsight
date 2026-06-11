#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> quant(n+1, 0);
  for(int i = 1; i <= n; i++){
    cin >> quant[i];
  }
  
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  dp[0][0] = 1;
  for(int kid = 1; kid <= n; kid++){
    vector<int> pref(m+1, 0);
    for(int used = 0; used <= m; used++){

      int value = dp[kid-1][used];
      int l = used;
      int r = used + min(quant[kid], m - used);

      pref[l] = mod(pref[l] + value, MOD);
      if(r < m) pref[r+1] = mod(pref[r+1] - value, MOD);
      /*for(int can = 0; can <= min(quant[kid], m-used); can++){
        dp[kid][used + can] = mod(dp[kid][used + can] + dp[kid-1][used], MOD);
      }*/
    }
    for(int k = 0; k <= m; k++){
      if(k) pref[k] = mod(pref[k] + pref[k-1], MOD);
      dp[kid][k] = mod(dp[kid][k] + pref[k], MOD);
    }
  }
  cout << dp[n][m] << '\n';
  return 0; 
}
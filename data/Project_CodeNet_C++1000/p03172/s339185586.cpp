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
  int n, k;
  cin >> n >> k;
  vector<int> v(n+1, 0);
  for(int i = 1; i <= n; i++){
    cin >> v[i];
  }
  vector<vector<int>> dp(n+5, vector<int>(k+5, 0));
  for(int i = n; i >= 1; i--){
    for(int j = k; j >= 0; j--){
      if(i == n){
        if(j <= v[i]) dp[i][j] = 1;
      }
      dp[i][j] = mod(dp[i][j] + (dp[i+1][j-min(j, v[i])] - dp[i+1][j+1]), MOD);
      dp[i][j] = mod(dp[i][j] + dp[i][j+1], MOD);
    }
  }
  cout << dp[1][k]%MOD << endl;
  return 0; 
}
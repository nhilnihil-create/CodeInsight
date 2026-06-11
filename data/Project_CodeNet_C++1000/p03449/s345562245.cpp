#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll dpa[107];
ll dpb[107];
ll dp[107];
int main(){
  ll n;
  cin >> n;
  vi a(n);
  vi b(n);
  cin >> a[0];
  dpa[0] = a[0];
  for(ll i=1;i<n;i++){
    cin >> a[i];
    dpa[i] = dpa[i - 1] + a[i];
  }
  cin >> b[0];
  dpb[0] = b[0];
  for(ll i=1;i<n;i++){
    cin >> b[i];
    dpb[i] = dpb[i - 1] + b[i];
  }
  dp[0] = dpa[0] + dpb[n-1];
  for (ll i = 1; i < n; i++){
    dp[i] = dpa[i] + dpb[n-1] - dpb[i - 1];
  }
  ll ans = 0;
  rep(i, n) chmax(ans, dp[i]);
  print(ans);
}
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
ll dp[100007];
int main(){
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  dp[0] = 0;
  ll count = 0;
  for (ll i = 1; i < n; i++){
    if(s[i]=='C'&&s[i-1]=='A'){
      count++;
    }
    dp[i] = count;
  }
  rep(i,q){
    ll l, r;
    cin >> l >> r;
    print(dp[r - 1] - dp[l-1]);
  }
}

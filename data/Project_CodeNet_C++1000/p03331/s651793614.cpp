#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
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
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  ll ans = INF;
  for (ll i = 1; i <= n / 2 + 1;i++){
    ll A = i;
    ll B = n - i;
    ll sum = 0;
    string a=to_string(A);
    string b=to_string(B);
    rep(j,sz(a)){
      sum += a[j] - '0';
    }
    rep(j,sz(b)){
      sum += b[j] - '0';
    }
    chmin(ans, sum);
  }
  print(ans);
}
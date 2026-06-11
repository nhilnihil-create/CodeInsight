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
  vector<Pll> a;
  ll sum = 0;
  rep(i, n){
    ll m;
    cin >> m;
    a.pb(mp(m, i));
    sum += m;
  }
  ll ans = 0;
  ll mini = INF;
  sort(all(a));
  rep(i,n){
    ll x = abs(a[i].F*n - sum);
    if(x<mini){
      ans = a[i].S;
      mini = x;
    }
    else if(x==mini){
      if(a[i].S<ans){
        ans = a[i].S;
      }
    }
  }
  print(ans);
}
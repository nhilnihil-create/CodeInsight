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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  vl a(n);
  vl b(n);
  vl dif(n);
  rep(i,n){
    cin >> a[i];
  }
  ll count = 0;
  ll minus = 0;
  rep(i, n){
    cin >> b[i];
    dif[i] = a[i] - b[i];
    if(dif[i]<0){
      minus -= dif[i];
      count++;
    }
  }
  sort(all(dif));
  ll OK = false;
  ll sum = 0;
  for (ll i = n - 1; i >= 0; i--){
    if(sum>=minus){
      OK = true;
      break;
    }
    sum += dif[i];
    count++;
    
  }
  if(OK){
    print(count);
  }
  else{
    print(-1);
  }
}
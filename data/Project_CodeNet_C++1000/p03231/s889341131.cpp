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
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin>>s>>t;
  bool OK = true;
  ll a = gcd(n, m);
  ll l = a * n / a * m / a;
  ll x = l / n, y = l / m;
  rep(i, n){
    if(i*x/y>sz(t)){
      break;
    }
    if((i*x)%y==0&&s[i]!=t[i*x/y]){
      OK = false;
    }
  }
  cout << (OK ? l : -1) << endl;
}
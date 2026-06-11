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

int main(){
  bool z = true;
  ll n;
  cin >> n;
  ll t1 = 0;
  ll v = 0;
  ll u = 0;
  rep(i,n){
    ll t;
    cin >> t;
    ll x, y;
    cin >> x >> y;
    ll num = abs(x - v) + abs(y - u);
    ll time = t - t1;
    if(num%2!=time%2)z = false;
    if (num > time)z = false;
    v = x;
    u = y;
    t1 = t;
  }
  if(z)print("Yes");
  else print("No");
}
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
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  ll n;
  cin >> n;
  double sum = 0;
  vector<pair<double, string>> a;
  rep(i,n){
    double x;
    string y;
    cin >> x >> y;
    a.pb(mp(x, y));
  }
  rep(i,n){
    if(a[i].S=="JPY"){
      sum += a[i].F;
    }
    else{
      sum += a[i].F * 380000;
    }
  }
  cout << fixed << setprecision(6) <<sum<< endl;
}
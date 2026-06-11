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
  ll h,w;
  cin>>h>>w;
  vll c(10,vl(10));
  rep(i,10){
      rep(j,10){
          cin>>c[i][j];
      }
  }
  vll a(h,vl(w));
  rep(i,h){
      rep(j,w){
          cin>>a[i][j];
      }
  }
  for (int k = 0; k < 10; k++){       // 経由する頂点
    for (int i = 0; i < 10; i++) {    // 始点
      for (int j = 0; j < 10; j++) {  // 終点
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
  ll sum=0;
  rep(i,h){
      rep(j,w){
          if(a[i][j]!=-1){
              sum+=c[a[i][j]][1];
          }
      }
  }
  print(sum);
}

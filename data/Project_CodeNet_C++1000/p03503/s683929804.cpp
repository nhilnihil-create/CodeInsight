#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
map<ll,ll> ma;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  int n;  cin >> n;
  vector<vector<int> > v(n);
  rep(i,0,n){
    v[i].resize(10);
    rep(j,0,10){
      cin >> v[i][j];
    }
  }
  vector<vector<ll> > p(n);
  rep(i,0,n){
    p[i].resize(11);
    rep(j,0,11){
      cin >> p[i][j];
    }
  }
  ll ma = -1e18;
  for(int bit=1 ; bit<(1<<10) ; bit++){
    int d[n];
    rep(i,0,n){
      d[i] = 0;
    }
    for(int i=0 ; i<10 ; i++){
      if(bit & (1<<i)){
        for(int j=0 ; j<n ; j++){
          if(v[j][i]){
            d[j]++;
          }
        }
      }
    }
    ll k=0;
    rep(i,0,n){
      k += p[i][d[i]];
    }
    chmax(ma, k);
  }
  cout << ma << endl;
  return 0;
}

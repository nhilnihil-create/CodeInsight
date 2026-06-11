#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) ((x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(ll a, ll b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a=b; return 1; } return 0; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w, 0));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];

  vector<pll> be, af;
  for(ll i = 0; i < h; i++){
    if(i % 2 == 1){
      for(ll j = w-1; j >= 0; j--){
        if(i == h-1 && j == 0) break;
        if(j != 0){
          if(a[i][j] % 2 == 1){
            a[i][j]--, a[i][j-1]++;
            be.pb(pll(i+1, j+1)), af.pb(pll(i+1, j));
          }
        }else{
          if(a[i][j] % 2 == 1){
            a[i][j]--, a[i+1][j]++;
            be.pb(pll(i+1, j+1)), af.pb(pll(i+2, j+1));
          }
        }
      }
    }else{
      for(ll j = 0; j < w; j++){
        if(i == h-1 && j == w-1) break;
        if(j != w-1){
          if(a[i][j] % 2 == 1){
            a[i][j]--, a[i][j+1]++;
            be.pb(pll(i+1, j+1)), af.pb(pll(i+1, j+2));
          }
        }else{
          if(a[i][j] % 2 == 1){
            a[i][j]--, a[i+1][j]++;
            be.pb(pll(i+1, j+1)), af.pb(pll(i+2, j+1));
          }
        }
      }
    }
  }

  cout << sz(be) << endl;
  for(ll i = 0; i < sz(be); i++){
    cout << be[i].first << ' ' << be[i].second << ' ' << af[i].first << ' ' << af[i].second << endl;
  }
  return 0;
}
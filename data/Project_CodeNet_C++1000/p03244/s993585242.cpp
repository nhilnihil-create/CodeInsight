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

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<ll> e, o;
  rep(i, 0, n){
    if(i % 2 == 0) e.pb(a[i]);
    else o.pb(a[i]);
  }
  sort(all(e)), sort(all(o));
  
  ll e1 = 0, e2 = 0, o1 = 0, o2 = 0;
  ll oindex = -1, eindex = -1;
  ll cnt = 1;
  for(ll i = 0; i < sz(e); i++){
    if(e[i] == e[i+1]) cnt++;
    else{
      if(cnt >= e1){
        eindex = i;
        e2 = e1;
        e1 = cnt;
      }else if(cnt >= e2){
        e2 = cnt;
      }
      cnt = 1;
    }
  }
  if(cnt != 1){
    if(cnt >= e1){
      eindex = sz(e)-1;
      e2 = e1;
      e1 = cnt;
    }else if(cnt >= e2){
      e2 = cnt;
    }
  }
  cnt = 1;
  for(ll i = 0; i < sz(o); i++){
    if(o[i] == o[i+1]) cnt++;
    else{
      if(cnt >= o1){
        oindex = i;
        o2 = o1;
        o1 = cnt;
      }else if(cnt >= o2){
        o2 = cnt;
      }
      cnt = 1;
    }
  }
  if(cnt != 1){
    if(cnt >= o1){
      oindex = sz(o)-1;
      o2 = o1;
      o1 = cnt;
    }else if(cnt >= o2){
      o2 = cnt;
    }
  }

  //cout << o2 << ' ' << e2 << endl;
  if(o[oindex] != e[eindex]) cout << n - e1 - o1 << endl;
  else cout << n - max(o1+e2, e1+o2) << endl;
  return 0;
}
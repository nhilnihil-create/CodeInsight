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
ll dpx[] = {-1, 0, 0, 1};
ll dpy[] = {0, 1, -1, 0};
int main(){
  ll h,w;
  cin >> h>>w ;
  vector<string> s(h+2);
  rep(i, w + 2) s[0].pb('.');
  rep(i, h){
    s[i].pb('.');
    cin >> s[i];
    s[i].pb('.');
  }
  rep(i, w + 2) s[h + 1].pb('.');
  bool ans = true;
  for (ll i = 1; i < h + 1;i++){
    for (ll j = 1; j < w + 1;j++){
      if(s[i][j]=='#'){
        bool tmp = true;
        rep(k, 4){
          if (s[i + dpy[k]][j+dpx[k]]=='#'){
            tmp = false;
          }
        }
        if(tmp){
          ans = false;
        }
      }
    }
  }
  if(ans){
    print("Yes");
  }
  else{
    print("No");
  }
}
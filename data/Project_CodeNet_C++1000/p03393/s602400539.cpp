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
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  string s;
  cin >> s;
  string t = "";
  if (s == "zyxwvutsrqponmlkjihgfedcba"){
    print(-1);
    return 0;
  }
  vector<bool> z(26,true);
  rep(i,sz(s)){
    rep(j,26){
      if(s[i]==alpha[j]){
        z[j] = false;
        break;
      }
    }
  }
  if(sz(s)<26){
    rep(i,26){
      if(z[i]){
        s.pb(alpha[i]);
        break;
      }
    }
  }
  else{
    char last;
    ll ind = 0;
    for (ll i = 25; i >= 0; i--){
      while(s[i]!=alpha[ind]){
        ind++;
      }
      if(i==25&&s[i]==alpha[ind]){
        last = alpha[ind];
      }
      t.pb(alpha[ind]);
      if(ind>25){
        last = s[sz(s) - 1];
      }
      s.erase(s.begin() + i);
      if(ind>25){
        i = -1;
        break;
      }
    }
    rep(i,sz(t)){
      if(last<t[i]){
        s.pb(t[i]);
        break;
      }
    }
  }
  print(s);
  //yzxwvutsrqponmlkjihgfedcba
}

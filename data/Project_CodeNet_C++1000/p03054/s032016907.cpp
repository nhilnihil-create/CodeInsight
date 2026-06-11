#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int h,w,n;
  cin >> h >> w >> n;
  int sh,sw;
  cin >> sh >> sw;
  string s,t;
  cin >> s >> t;
  int tsh = sh;
  bool flag = false;
  rep(i,0,n){
    if(s[i] == 'U'){
      tsh--;
    }
    if(tsh == 0){
      // cout << "a" << endl;
      flag = true;
    }
    if(t[i] == 'D'){
      if(tsh != h) tsh++;
    }
  }
  tsh = sh;
  rep(i,0,n){
    if(s[i] == 'D'){
      tsh++;
    }
    if(tsh == h+1){
      // cout << "b" << endl;
      flag = true;
    }
    if(t[i] == 'U'){
      if(tsh != 1) tsh--;
    }
  }
  int tsw = sw;
  rep(i,0,n){
    if(s[i] == 'R'){
      tsw++;
    }
    if(tsw == w+1){
      flag = true;
      // cout << "c" << endl;
    }
    if(t[i] == 'L'){
      if(tsw != 1) tsw--;
    }
  }
  tsw = sw;
  rep(i,0,n){
    if(s[i] == 'L'){
      tsw--;
    }
    if(tsw == 0){
      flag = true;
      // cout << "d" << endl;
    }
    if(t[i] == 'R'){
      if(tsw != w) tsw++;
    }
  }
  if(flag) cout << "NO" << endl;
  else cout << "YES" << endl;
}
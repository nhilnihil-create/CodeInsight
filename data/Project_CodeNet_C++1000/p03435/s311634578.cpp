#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  vvi c(3, vi(3));
  rep(i,3){
    rep(j,3) cin >> c.at(i).at(j);
  }
  
  rep(i,2){
    int p = c.at(i).at(2) - c.at(i+1).at(2);
    rep(j,2){
      if(p == c.at(i).at(j) - c.at(i+1).at(j)) continue;
      NO;
      return 0;
    }
  }
  rep(j,2){
    int p = c.at(2).at(j) - c.at(2).at(j+1);
    rep(i,2){
      if(p == c.at(i).at(j) - c.at(i).at(j+1)) continue;
      NO;
      return 0;
    }
  }
  YES;
  return 0;
}

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
  int n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a.at(i);
  sort(all(a));
  long g = __gcd(a.at(0), a.at(1));
  vl list;
  REP(i, 1, sqrt(g)+1){
    if(g % i == 0){
      list.push_back(i);
      list.push_back(g/i);
    }
  }
  long ans = 1;
  
  for(long v : list){
    int ikkai = 1;
    REP(i,2,n){
      if(a.at(i) % v != 0){
        if(ikkai) ikkai--;
        else {
          ikkai--;
          break;
        }
      }
    }
    if(ikkai >= 0) chmax(ans, v);
  }
  vl list2;
  REP(i, 1, sqrt(a.at(0))+1){
    if(a.at(0) % i == 0){
      list2.push_back(i);
      list2.push_back(a.at(0)/i);
    }
  }
  for(long v : list2){
    int ikkai = 1;
    rep(i,n){
      if(i == 0) continue;
      if(a.at(i) % v != 0){
        if(ikkai) ikkai--;
        else{
          ikkai--;
          break;
        }
      }
    }
    if(ikkai >= 0) chmax(ans, v);
  }
  vl list3;
  REP(i, 1, sqrt(a.at(1))+1){
    if(a.at(1) % i == 0){
      list3.push_back(i);
      list3.push_back(a.at(1)/i);
    }
  }
  for(long v : list3){
    int ikkai = 1;
    rep(i,n){
      if(i == 1) continue;
      if(a.at(i) % v != 0){
        if(ikkai) ikkai--;
        else{
          ikkai--;
          break;
        }
      }
    }
    if(ikkai >= 0) chmax(ans, v);
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << 
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " ";} cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  //input
  string s;
  cin >> s;
  //文字列sのサイズn取得
  int n = s.size();

  //部分文字列の長さを決定　n-7
  int m = n - 7;
  //サイズ７の文字列Tの作製して比較REP(k,0,8) //0-7まで
  //keyenceとTの比較　bool okを定義

  
  bool ok = false;
  REP(k,8){
    string T = "";
    REP(i,k){
      T += s[i];
    }
    REP2(i,k+m,n){
      T += s[i];
    }
    //cout << T << endl;
    if(T == "keyence") {
      ok = true;
      break;
    }
  }

  //output
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
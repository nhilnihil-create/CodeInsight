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
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  //in
  int n, s;
  cin >> n >> s;
  vector<int> x(n);
  REP(i,n) cin >> x[i];
  x.push_back(s);
  // REP(i,n) {
  //   int xx;
  //   cin >> xx;
  //   //if(xx == s) continue; //xx != s が条件にあるからいらない
  //   x.push_back(xx);
  // }


  debug(x);
  sort(ALL(x));

  vector<int> len(x.size() - 1);
  
  REP(i,len.size()){
    len[i] = abs(x[i+1]- x[i]);
  }

  debug(len);
  //x座標と同じ値がなければ配列に追加
  int g = len[0];
  REP(i,len.size()){
    g = __gcd(g,len[i]);
  }

  cout << g << endl;

  return 0;
}

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
  int x1, y1, x2, y2;
  cin >> x1 >>  y1 >>  x2 >>  y2;
  int dx = -(x1 - x2);
  int dy = -(y1 - y2);
  int x3 = x2 - dy;
  int y3 = y2 + dx;
  int x4 = x1 - dy;
  int y4 = y1 + dx;
  cout << x3 << " " << y3 << " " << x4 << " "  << y4 << endl; 
  return 0;
}
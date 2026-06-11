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
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x;
  x.push_back(X);
  vector<int> y;
  y.push_back(Y);

  REP(i,n){
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
  REP(i,m){
    int yy;
    cin >> yy;
    y.push_back(yy);
  }

  sort(RALL(x));
  sort(ALL(y));
  if(x[0] < y[0]) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
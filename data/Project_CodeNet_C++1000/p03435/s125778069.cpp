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
#define debug(var)  do{cout << #var <<  " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  const int N = 3;
  int c[N][N];
  REP(i,N)REP(j,N){
      int cx;
      cin >> cx;
      c[i][j] = cx;
  }

  vector<int> a(N);
  vector<int> b(N);
  a[0] = 0;
  REP(i,N) b[i] = c[0][i] - a[0];
  a[1] = c[1][0] - b[0];
  a[2] = c[2][0] - b[0];
  bool ok = true;
  REP(i,N)REP(j,N){
    if(c[i][j] != a[i]+b[j]){
      ok = false;
      break;
    }
  }
  debug(a);
  debug(b);
  debug(c);

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;  
  return 0;
}
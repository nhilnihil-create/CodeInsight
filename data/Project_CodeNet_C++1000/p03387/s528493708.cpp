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
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  sort(ALL(a));
  int cnt = 0; 
  while(1){
    if(a[1] == a[2]) break;
    else {
      a[0]++;
      a[1]++;
    }
    cnt++;
  }

  while(1){
    if(a[0] == a[1]) break;
    if(a[0] == a[1]+ 1){
      cnt++;
      break;
    }
    a[0] += 2;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
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
  int n;
  cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  //flg 0: h != 0 でcnt++ /flg = 1 0発見でflg 0に　初期flg-1
  int cnt = 0;
  REP(j,100){
    int flg = -1;
    REP(i,n){
      if(flg <= 0){
        if(h[i] != 0) {
          h[i]--;
          cnt++;
          flg = 1;
        }
      }
      else if (flg == 1){
        if(h[i] == 0) flg = 0;
        else h[i]--;
      }
    }
    if(flg == -1) break;
  }

  cout << cnt << endl;

  return 0;
}
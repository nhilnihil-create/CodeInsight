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
  //入力
  int n;
  cin >> n;
  map <int,int> a;
  map <int,int> b;
  REP(i,n){
    int v;
    cin >> v;
    if(i%2 == 0) a[v]++;
    else b[v]++;
  } 
  //変換数は，n/2 - 最大値をそれぞれ足したもの
  int maxa = 0;
  int maxkey_a = 0;
  int maxb = 0;
  int maxkey_b = 0;

  for(auto x: a) {
    if(x.second >= maxa){
      maxa = x.second;
      maxkey_a = x.first;
    }
  }

  for(auto x: b) {
    if(x.second >= maxb){
      maxb = x.second;
      maxkey_b = x.first;
    }
  }

  //
  if(maxkey_a == maxkey_b){
    int max2a = 0;
    int max2key_a = 0;
    for(auto x: a){
      if(x.first == maxkey_a) continue;
      if(x.second >= max2a){
      max2a = x.second;
      max2key_a = x.first;
      }
    }

    int max2b = 0;
    int max2key_b = 0;
    for(auto x: b){
      if(x.first == maxkey_b) continue;
      if(x.second >= max2b){
      max2b = x.second;
      max2key_b = x.first;
      }
    }

    if(maxa - max2a >= maxb - max2b) maxb = max2b;
    else maxa = max2a;
  }

  int ans = n - maxa - maxb;
  cout << ans << endl;
  return 0;
}
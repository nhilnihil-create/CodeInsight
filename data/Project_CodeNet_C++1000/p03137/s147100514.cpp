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
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  REP(i,m) cin >> x[i];

  sort(ALL(x));

  vector<ll> dist(m-1);
  REP(i,m - 1){
    dist[i] = (ll)abs(x[i] - x[i+1]);
  }

  sort(RALL(dist));
  ll sum = 0;
  REP(i,m-1){
    if(i < n - 1) continue;
    sum += (ll)dist[i];
  }
  cout << sum << endl;
  return 0;
}
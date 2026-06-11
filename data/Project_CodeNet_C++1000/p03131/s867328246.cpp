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
  int k, a, b;
  cin >> k >> a >> b;
  if(b - a < 2) {
    cout << k+1 << endl;
    return 0;
  }

  // b - a >= 2;
  int d = k - a + 1;
  ll sum = 0;
  if(d <= 1){
    cout << k + 1 << endl;
    return 0;
  }

  if(d%2 == 0) sum = a + ((ll)(b - a) * (d/2));
  else sum =  a + ((ll)(b - a) * (d/2)) +1;

  cout << sum << endl;
  debug(sum);

  return 0;
}
/*
48518828981938099
12345678912345678
*/
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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  //累積和
  vector<int> sum(n);
  sum[0] = 0;
  int tmpsum = 0;
  REP(i,n-1){
    if(s[i] == 'A' && s[i+1] == 'C') tmpsum++;
    sum[i+1] = tmpsum; 
  }
  debug(sum);

  REP(i,q){
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ans = sum[r] - sum[l];
    cout << ans << endl;
  }
  return 0;
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//-2のn乗を返す
ll func(ll n){
  if(n == 0) return 1;
  ll res = -2;
  rep(i, n-1)
    res *= -2;
  
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<pll> vc;

  if(n == 0) cout << 0 << ln;
  else{
  bool f = false; int cnt = 0;
  ll plus = 0, minus = 0;
  while(!f){
    ll num = func(cnt);
    if(cnt%2 == 0){
     plus += num; 
     pll p(plus, plus - num + 1);
     vc.push_back(p);
     if(n <= plus && n >= plus - num + 1) f = true;
    }else{
      minus += num;
      pll p(minus - num - 1, minus);
      vc.push_back(p);
      if(n >= minus && n <= minus - num - 1) f = true;
    }
    cnt++;
  }

  string res;
  for(int i = cnt - 1; i >= 0; i--){
    //cout << "n:" << n << ln;
    ll mx = vc[i].first; ll mn = vc[i].second;
    if(n <= mx & n >= mn){
      res += "1";
      n -= func(i);
    } else{
      res += "0";
    }
  }
   cout << res << ln;
  }
}
  

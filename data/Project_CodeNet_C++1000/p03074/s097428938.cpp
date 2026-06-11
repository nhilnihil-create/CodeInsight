#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  int n, k, t = 0, u = 0, a = 0;
  scanf("%d %d", &n, &k);
  string s;
  cin >> s;
  v1i p;
  rep(i, n+1){
    if(i == n){
      if(s[i-1] == '1') p.push_back(u);
      else{
        p.push_back(t);
        p.push_back(0);
      }
      break;
    }
    if(s[i] == '1'){
      if(t > 0 || i == 0) p.push_back(t);
      t = 0;
      ++u;
    }
    else{
      if(u > 0) p.push_back(u);
      u = 0;
      ++t;
    }
  }
  vector<pii> v; t = 0;
  rep(i, p.size()/2){
    if(i == 0 && p[0] > 0) v.push_back({0, 0});
    v.push_back({t+p[i*2], t+p[i*2]+p[i*2+1]});
    t += p[i*2]+p[i*2+1];
  }
  k = min(k, (int)v.size()-1);
  rep(i, v.size()-k) a = max(a, v[k+i].se-v[i].fi);
  printf("%d\n", a);
  return 0;
}

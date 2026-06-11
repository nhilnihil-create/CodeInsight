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
  int n, s = 0;
  scanf("%d", &n);
  vector<pii> a(n), b(n); v1b c(n, 1);
  rep(i, n) scanf("%d %d", &a[i].fi, &a[i].se);
  rep(i, n) scanf("%d %d", &b[i].fi, &b[i].se);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  rep(i, n){
    int m = -1, t = 0;
    while(a[t].fi < b[i].fi && t < n){
      if(c[t] && a[t].se < b[i].se) m = max(m, a[t].se);
      ++t;
    }
    rrep(j, t){
      if(c[j] && m == a[j].se){
        ++s;
        c[j] = 0;
        break;
      }
    }
  }
  printf("%d\n", s);
  return 0;
}
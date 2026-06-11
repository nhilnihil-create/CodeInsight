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
  int n;
  scanf("%d", &n);
  v1i v(n+2, 0), u(n+2, 0), w(n);
  rep(i, n) scanf("%d", &v[i+1]);
  rep(i, n+1){
    u[i+1] = u[i] + abs(v[i+1]-v[i]);
    if(i < n) w[i] = abs(v[i+2]-v[i]);
  }
  rep(i, n) printf("%d\n", u[i]+w[i]+u[n+1]-u[i+2]);
  return 0;
}
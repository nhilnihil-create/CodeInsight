#include <bits/stdc++.h>
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, irep, _rep)(__VA_ARGS__)
#define rep1(...) GET_REP(__VA_ARGS__, irep1, _rep1)(__VA_ARGS__)
#define _rep(i, n) irep (i, 0, n)
#define _rep1(i, n) irep1(i, 1, n)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define irep1(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(X, x) for (auto &&X : x)
#define all(x) begin(x), end(x)
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
  #define debug(x) cout << #x " => " << (x) << endl
#else
  #define debug(x) 0
#endif
using lint = long long;
constexpr int    INF  = 1 << 28;
constexpr lint   INFL = 1LL << 60;
constexpr int    MOD  = (int)1e9 + 7;
constexpr double EPS  = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> td(n);
  rep (i, n) cin >> td[i].first >> td[i].second;
  unordered_map<int, int> neta_max;
  rep (i, n) neta_max[td[i].first] = max(neta_max[td[i].first], td[i].second);
  sort(all(td), [](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; });
  unordered_map<int, int> neta_num;
  lint sum = 0;
  rep (i, k) {
    sum += td[i].second;
    ++neta_num[td[i].first];
  }
  lint num  = neta_num.size();
  lint maxi = sum + num * num;
  allrep (p, neta_num) neta_max.erase(p.first);
  vector<int> left(neta_max.size());
  auto itr = neta_max.begin();
  rep (i, left.size()) {
    left[i] = itr->second;
    ++itr;
  }
  sort(all(left), greater<int>());
  int now = k - 1;
  rep (i, left.size()) {
    while (now >= 0 && neta_num[td[now].first] <= 1) --now;
    if (now < 0) break;
    sum = sum - td[now].second + left[i];
    ++num;
    maxi = max(maxi, sum + num * num);
    --neta_num[td[now].first];
    --now;
  }
  cout << maxi << endl;
  return 0;
}
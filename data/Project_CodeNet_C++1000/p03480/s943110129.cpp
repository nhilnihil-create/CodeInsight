#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define rep(x, a, b) for(auto x = a; x != b; ++x)

const int N = 1e5 + 5;

int n;
char s[N];
int a[N], comp[N], cnt[N];

bool possible(int k) {
  set<int> rem;
  for(int i = 1; i <= n+1; ++i) {
    rem.insert(i);
  }

  int tym = 0;

  while(rem.size()) {
    tym++;

    vector<int> Q = {*rem.begin()};
    rem.erase(rem.begin());

    for(int b = 0; b < (int)Q.size(); ++b) {
      int u = Q[b];
      comp[u] = tym;

      auto l = rem.upper_bound(u - k);
      rep(it, rem.begin(), l) Q.push_back(*it);
      rem.erase(rem.begin(), l);

      auto r = rem.lower_bound(u + k);
      rep(it, r, rem.end()) Q.push_back(*it);
      rem.erase(r, rem.end());
    }
  }
  memset(cnt, 0, sizeof cnt);
  for(int i = 1; i <= n+1; ++i) {
    if(a[i] & 1) cnt[comp[i]]++;
  }
  for(int i = 1; i <= tym; ++i) {
    if(cnt[i] & 1) return false;
  }
  return true;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  scanf("%s", s+1);
  n = strlen(s+1);
  a[1] = s[1] - '0';
  for(int i = 2; i <= n; ++i) {
    a[i] = (s[i-1] - '0') ^ (s[i] - '0');
  }
  a[n+1] = s[n] - '0';
  int lo = 1, hi = n, ans = -1;
  while(lo <= hi) {
    int mid = (lo + hi) >> 1;
    if(possible(mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
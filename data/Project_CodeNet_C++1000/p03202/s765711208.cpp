#include <bits/stdc++.h>
#define inf (long long)(2e18)
using namespace std;

long long n;
vector<long long> a;

long long solve();
bool check(long long x);

int main() {
  cin >> n;
  a.resize(n);
  for (auto& p : a) cin >> p;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long l = 0, r = n + 2;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  return r;
}

bool check(long long x) {
  using P = pair<long long, long long>;
  vector<P> now(1, P(0, 0));
  for (int i = 0; i < n; ++i) {
    P nxt = P(0, 0);
    while (now.back().first >= a[i] || nxt.second + 1 > x) {
      if (now.size() == 1) return 0;
      nxt = now.back();
      now.pop_back();
    }
    nxt.first = min(nxt.first - 1, a[i] - 1);
    if (nxt.first > now.back().first) now.push_back(nxt);
    ++nxt.first;
    ++nxt.second;
    if (nxt.first) now.push_back(nxt);
    nxt.first = a[i];
    nxt.second = 1;
    if (nxt.first > now.back().first) now.push_back(nxt);
  }
  return 1;
}
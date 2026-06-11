#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  auto cmp = [&](int i, int j) {
    return a[i].first < a[j].first;
  };
  auto cmp2 = [&](int i, int j) {
    return a[i].second > a[j].second;
  };
  auto proc = [&](bool l) -> long long {
    priority_queue<int, vector<int>, decltype(cmp)> maxl(cmp);
    priority_queue<int, vector<int>, decltype(cmp2)> minr(cmp2);
    for (int i = 0; i < n; ++i) {
      maxl.push(i);
      minr.push(i);
    }
    vector<bool> used(n);
    long long d = 0;
    int next, pos;
    if (l) {
      next = minr.top();
      pos = min(0, a[next].second);
      if (a[next].first > 0) {
        return -1;
      }
    } else {
      next = maxl.top();
      pos = max(0, a[next].first);
      if (a[next].second < 0) {
        return -1;
      }
    }
    used[next] = true;
    d += abs(pos);
    for (int i = 1; i < n; ++i) {
      while (!maxl.empty() && used[maxl.top()]) {
        maxl.pop();
      }
      while (!minr.empty() && used[minr.top()]) {
        minr.pop();
      }
      int next, npos;
      if (i % 2 == l) {
        next = maxl.top();
        npos = max(pos, a[next].first);
      } else {
        next = minr.top();
        npos = min(pos, a[next].second);
      }
      used[next] = true;
      d += abs(pos - npos);
      pos = npos;
    }
    d += abs(pos);
    return d;
  };
  cout << max(proc(0), proc(1)) << endl;
  return 0;
}

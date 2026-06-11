#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> d(n);
  vector<int> parent(n, -1);
  vector<int> p(n);
  vector<ll> size(n, 1);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    p[i] = i;
    mp[d[i]] = i;
  }
  sort(p.begin(), p.end(), [&](int i, int j) { return d[i] > d[j]; });
  int r = p.back();
  p.pop_back();
  for (int i : p) {
    ll tmp = d[i] - n + 2 * size[i];
    if (tmp < d[i] && mp.count(tmp)) {
      parent[i] = mp[tmp];
      size[parent[i]] += size[i];
    } else {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<ll> sum(n);
  for (int i : p) {
    sum[parent[i]] += sum[i] + size[i];
  }
  reverse(p.begin(), p.end());
  vector<ll> correct(n);
  correct[r] = sum[r];
  for (int i : p) {
    correct[i] = correct[parent[i]] + n - 2 * size[i];
  }
  if (correct != d) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (parent[i] != -1) {
      cout << i+1 << ' ' << parent[i]+1 << '\n';
    }
  }
}

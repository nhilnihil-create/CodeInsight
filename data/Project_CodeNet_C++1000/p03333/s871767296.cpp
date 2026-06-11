#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> lr[2];
long long n, now, ans = 0;

bool asc0(pair<long long, long long> l,
          pair<long long, long long> r) {
  return l.second < r.second;
}
bool asc1(pair<long long, long long> l,
          pair<long long, long long> r) {
  return l.first > r.first;
}

int main() {
  long long i, l, r;
  cin >> n;
  for(i = 0; i < n; ++i) {
    cin >> l >> r;
    lr[0].push_back(make_pair(l, r));
    lr[1].push_back(make_pair(l, r));
  }
  sort(lr[0].begin(), lr[0].end(), asc0);
  sort(lr[1].begin(), lr[1].end(), asc1);
  for(i = 0; i < (n + 1) / 2; ++i) {
    if(i < lr[0].size()) now -= lr[0][i].second;
    if(now * 2 > ans) ans = now * 2;
    if(n % 2 == 1 && i == (n + 1) / 2 - 1) break;
    if(i < lr[1].size()) now += lr[1][i].first;
    if(now * 2 > ans) ans = now * 2;
  }
  now = 0;
  for(i = 0; i < (n + 1) / 2; ++i) {
    if(i < lr[1].size()) now += lr[1][i].first;
    if(now * 2 > ans) ans = now * 2;
    if(n % 2 == 1 && i == (n + 1) / 2 - 1) break;
    if(i < lr[0].size()) now -= lr[0][i].second;
    if(now * 2 > ans) ans = now * 2;
  }
  cout << ans << endl;
  return 0;
}

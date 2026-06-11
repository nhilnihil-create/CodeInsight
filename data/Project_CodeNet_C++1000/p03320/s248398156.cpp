#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1000000000000000;
int K;
using P = pair<ll, double>;
vector<P> v;

int digitSum(ll x) {
  int res = 0;
  while (x) res += x % 10, x /= 10;
  return res;
}

double f(ll x) {
  return (double)x / digitSum(x);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> K;
  for (int i = 1; i < 100000; i++) {
    ll tmp = i;
    while (tmp <= INF) {
      v.emplace_back(tmp, f(tmp));
      tmp = tmp * 10 + 9;
    }
  }
  sort(v.begin(), v.end(), [&](P a, P b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
  });
  
  ll last = 0, cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first > last) {
      last = v[i].first;
      cout << last << endl;
      cnt++;
      if (cnt == K) break;
    }
  }

  return 0;
}
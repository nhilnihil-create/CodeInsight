#include <bits/stdc++.h>
using namespace std;

struct data {
  long long a, b;
};
bool operator<(const data &l, const data &r) {
  return l.b - l.a > r.b - r.a;
}

long long n;
vector<data> v;

long long solve();

int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; ++i) cin >> v[i].a >> v[i].b;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0, num = (long long)1e10;
  bool ch = 1;
  for(int i = 0; i < n; ++i)
    if(v[i].a != v[i].b) ch = 0;
  if(ch) return 0;
  for(int i = 0; i < n; ++i) {
    ans += v[i].b;
    if(v[i].a > v[i].b) num = min(num, v[i].b);
  }
  return ans - num;
}
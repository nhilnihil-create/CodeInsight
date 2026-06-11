#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

bool ok(const vecint& a, const int th) {
  ll n = a.size();
  vecint v(n*4);
  int offset = n*2;
  ll cnt = 0;
  ll sum = 0;
  REP(i,n) {
    v[offset] += 1;
    if (a[i] >= th) {
      offset -= 1;
      sum -= v[offset];
    } else {
      sum += v[offset];
      offset += 1;
    }
    cnt += sum;
  }
  ll m = n * (n+1) / 2;
  ll mid = m/2 + 1;
  return cnt >= mid;
}

int main()
{
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vecint a(n);
  REP(i,n) cin>>a[i];
  vecint b = a;
  b.push_back(0);
  b.push_back(1000000007);
  sort(ALL(b));
  b.erase(unique(ALL(b)), end(b));
  int hi = b.size()-1;
  int lo = 0;
  while ((hi - lo) > 1) {
    int mid = (hi + lo) / 2;
    if (ok(a, b[mid])) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << b[lo] << endl;
  return 0;
}

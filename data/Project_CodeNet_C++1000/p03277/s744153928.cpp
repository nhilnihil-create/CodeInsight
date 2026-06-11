#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

bool ok(const vecint& a, const int th, vecint& v) {
  ll n = a.size();
  v.assign(n*3, 0);
  int offset = n*1.5;
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
  int n;
  scanf("%d", &n);
  vecint a(n);
  string line;
  getline(cin, line);
  getline(cin, line);
  int i = 0;
  int num = 0;
  for (char c : line) {
    if (isdigit(c)) {
      num *= 10;
      num += c - '0';
    } else {
      a[i] = num;
      ++i;
      num = 0;
    }
  }
  a[i] = num;
  vecint b = a;
  b.push_back(0);
  b.push_back(1000000007);
  sort(ALL(b));
  b.erase(unique(ALL(b)), end(b));
  int hi = b.size() - 1;
  int lo = 0;
  vecint v(n*4);
  while ((hi - lo) > 1) {
    int mid = (hi + lo) / 2;
    if (ok(a, b[mid], v)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%d\n", b[lo]);
  return 0;
}

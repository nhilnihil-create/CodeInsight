#include <iostream>
using namespace std;
constexpr long INF = 1L << 60;

long n, a[100010];

bool C(long x, bool f) {
  for(int i = 0; i < n; ++i) {
    x = x - x % a[i];
  }
  return (f ? x >= 2 : x <= 2);
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  long l = 0, r = INF, L, R;
  while(r - l > 1) {
    long mid = (l + r)>>1;
    if(C(mid,1)) r = mid;
    else l = mid;
  }
  L = r;

  l = 0, r = INF;
  while(r - l > 1) {
    long mid = (l + r)>>1;
    if(C(mid,0)) l = mid;
    else r = mid;
  }
  R = l;

  if(L < R) cout << L << endl << R;
  else cout << -1;

  return 0;
}
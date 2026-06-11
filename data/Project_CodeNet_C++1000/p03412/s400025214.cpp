#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
const int maxn = 200005;
using ll = long long;
int A[maxn], B[maxn];
int SA[maxn], SB[maxn];
int n;
inline void resort(int p, int *A, int *SA) {
  std::vector<int> V1, V2;
  for(int i = 1; i <= n; i ++) {
    int th = SA[i];
    if((1 << p) & A[th]) V2.push_back(th);
    else V1.push_back(th);
  }
  int cnt = 0;
  for(int th : V1) {
    SA[++ cnt] = th;
  }
  for(int th : V2) {
    SA[++ cnt] = th;
  }
#ifdef LOCAL
  printf("SA(%d) :", p);
  for(int i = 1; i <= n; i ++) {
    printf(" %d", SA[i]);
  }
  puts("");
#endif
}
inline ll calc(int bt, int p) {
  int pt = n; ll ans = 0;
  int vp = (1 << (bt + 1)) - 1;
  for(int i = 1; i <= n; i ++) {
    int th = SA[i];
    while(pt > 0 && (A[th] & vp) + (B[SB[pt]] & vp) > p) {
      pt --;
    }
    ans += pt;
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++) {
    scanf("%d", &A[i]); SA[i] = i;
  }
  for(int i = 1; i <= n; i ++) {
    scanf("%d", &B[i]); SB[i] = i;
  }
  int ans = 0;
  for(int i = 0; i <= 28; i ++) {
    resort(i, A, SA); resort(i, B, SB);
    ll val = calc(i, (1 << (i + 1)) - 1) - calc(i, (1 << i) - 1);
    val += calc(i, (1 << (i + 2)) - 1) - calc(i, (3 << i) - 1);
    if(1LL & val) ans |= (1 << i);
#ifdef LOCAL
    printf("Sol(%d) : %lld\n", i, val);
#endif
  }
  printf("%d\n", ans);
  return 0;
}
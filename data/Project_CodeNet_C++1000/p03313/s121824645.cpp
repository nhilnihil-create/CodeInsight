#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = (1 << 18) + 1;
typedef pair<int, int> P;
int d[N];
P f[N];

P merge(P A, P B) {
  if(A.fi < B.fi) swap(A, B);
  return P(A.fi, max(A.se, B.fi));
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < (1 << n); ++i) {
    scanf("%d", &f[i].fi);
    f[i].se = 0;
  }
  for(int i = 1; i < (1 << n); i <<= 1) {
    for(int j = 1; j < (1 << n); ++j) {
      if(i & j) {
        f[j] = merge(f[j], f[j ^ i]);
      }
    }
  }
  for(int i = 1; i < (1 << n); ++i) {
    d[i] = max(d[i - 1], f[i].fi + f[i].se);
    printf("%d\n", d[i]);
  }
  return 0;
}
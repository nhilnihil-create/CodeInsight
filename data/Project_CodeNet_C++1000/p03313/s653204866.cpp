#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, a[1 << 18], mx1[1 << 18], mx2[1 << 18];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); ++i) {
    scanf("%d", &a[i]);
    mx1[i] = a[i];
  }

  for (int j = 0; j < n; ++j) {
    for (int K = 1; K < (1 << n); ++K) {
      if (K >> j & 1) {
        int P = K ^ (1 << j);
        auto update = [&](int X) {
          if (X >= mx2[K]) {
            mx2[K] = X;
            if (mx2[K] > mx1[K]) {
              swap(mx1[K], mx2[K]);
            }
          }
        };
        update(mx1[P]);
        update(mx2[P]);
      }
    }
  }

  int mx = 0; 
  for (int K = 1; K < (1 << n); ++K) {
    mx = max(mx, mx1[K] + mx2[K]); 
    printf("%d\n", mx);
  }
}

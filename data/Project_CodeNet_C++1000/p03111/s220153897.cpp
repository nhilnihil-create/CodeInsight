#include <bits/stdc++.h>
using namespace std;

int l[8];
int n;
int calc(int selected, int len) {
  int ret = 0;
  int tmp_len = 0;
  for (int i=0; i<n; i++) {
    if ((selected >> i) & 1) {
      tmp_len += l[i];
      ret += 10;
    }
  }
  ret -= 10;
  ret += abs(len - tmp_len);
  return ret;
}
int main() {
  int a, b, c;
  cin>>n>>a>>b>>c;
  for (int i=0; i<n; i++) cin>>l[i];
  int ans = 1e9;
  for (int i=1; i<(1<<n); i++) {
    for (int j=1; j<(1<<n); j++) {
      if ((i & j) != 0) {
        continue;
      }
      for (int k=1; k<(1<<n); k++) {
        if ((i & k) != 0 || (j & k) != 0) {
          continue;
        }
        ans = min(calc(i, a) + calc(j, b) + calc(k, c), ans);
      }
    }
  }
  cout<<ans<<endl;
}
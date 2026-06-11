#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans=0;
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int x100=0;
  int x50=0;
  for (int i=0; i<=(X/500); i++) {
    if (i>A) continue;
    x100=X-(500*i);
    if (x100 == 0) {
      ans++;
      continue;
    }
    for (int j=0; j<=(x100/100); j++) {
      if (j>B) continue;
      x50=x100-(100*j);
      if (x50 == 0) {
        ans++;
        continue;
      }
      for (int k=0; k<=(x50/50); k++) {
        if (k>C) continue;
        if (x50-(50*k) == 0) ans++;
      }
    }
  }
  cout << ans << endl;
}

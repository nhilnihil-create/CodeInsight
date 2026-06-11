#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k, c, ans, cnt = 0;
  scanf("%d %d %d", &a, &b, &k);
  c = min(a, b);
  for(int i = c; i > 0; i--) {
    if(a % i == 0 && b % i == 0) {
      cnt++;
    }
    if(cnt == k) {
      ans = i;
      break;
    }
  }
  cout << ans;
}
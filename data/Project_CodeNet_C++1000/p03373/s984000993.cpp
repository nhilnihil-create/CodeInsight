#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 2e9;
  x <<= 1, y <<= 1;
  for(int i = 0; i <= max(x, y); ++i) {
    int pos = i * c;
    if(i <= x) {
      pos += (((x - i) & 1) + (x - i) / 2) * a;
    } 
    if(i <= y) {
      pos += (((y - i) & 1) + (y - i) / 2) * b;
    }
//    printf("%d %d\n", i, pos);
    ans = min(ans, pos);
  }  
  printf("%d\n", ans);
  return 0;
}
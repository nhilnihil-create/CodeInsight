#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, M, X, y, a = 0, b = 0, ans = 0;
  cin >> N >> M >> X;
  
  for (int i = 0; i < M; i++) {
    cin >> y;
    if (y < X) a++;
    else b++;
  }
  
  if (a < b) ans = a;
  else ans = b;
  
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x; cin >> a >> b >> c >> x;

  int ans = 0;
  for(int i = 0; i <= a ; i++) {
    for(int j = 0; j <= b; j++) {
      int check = 500 * i + 100 * j;
      if(check <= x && x <= check + 50 * c) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

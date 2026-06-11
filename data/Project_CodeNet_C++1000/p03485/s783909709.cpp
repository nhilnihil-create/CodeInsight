#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0, b = 0;
  cin >> a >> b;
  int ans = ( a + b ) / 2;
  if( ( a + b ) % 2 != 0 ){
    ans += 1;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int s;
  cin >> s;

  if ( 1==s || 2==s || 4==s ) {
    cout << 4 <<endl;
    return 0;
  }

  int x = 0;
  rep( i, 1, INT_MAX ) {
    if ( 1 == i ) x = s;
    if ( 1 < i ) {
      if (x%2) x = 3*x + 1;
      else x /= 2;
    }
    if (x == 4) {
      cout << i + 3 << endl;
      break;
    }
  }
  return 0;
}

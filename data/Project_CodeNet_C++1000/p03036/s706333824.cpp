#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int r, D, x; cin >> r >> D >> x;

  rep( i, 0, 10 ) {
    x = x * r - D;
    cout << x << endl;
  }
}

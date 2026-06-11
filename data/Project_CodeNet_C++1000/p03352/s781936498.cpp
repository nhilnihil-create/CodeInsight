#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int X;
  cin >> X;
  vector<bool> expo(X+1);

  expo.at(1) = true;

  for (int b=2; b<=X; b++) {
    int v = b*b;
    while(v<=X) {
      expo.at(v) = true;
      v *= b;
    }
  }
  for (int i=X; i>=1; i--) {
    if (expo.at(i)) {
      cout << i << endl;
      break;
    }
  }
}

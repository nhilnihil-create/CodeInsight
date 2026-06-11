#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int X;
  cin >> X;

  int tmp = X;
  int F_X = 0;
    
  while(tmp != 0) {
    F_X += (tmp % 10);
    tmp /= 10;
  }
  
  if ( (X % F_X) == 0 ) {
    cout << "Yes" << endl;
  } else {
    cout << "No"  << endl;
  }
}
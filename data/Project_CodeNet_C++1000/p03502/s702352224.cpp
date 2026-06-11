#include <bits/stdc++.h>
using namespace std;


int main() {
  int N1,N2,S;
  cin >> N1;
  N2 = N1;
  while(N2 / 10 >= 1) {
    S += N2 % 10;
    N2 /= 10;
  }
  S += N2;
  if(N1 % S == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

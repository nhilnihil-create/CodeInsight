#include <bits/stdc++.h>
using namespace std;

int main() {
  long A,B,K;
  cin >> A >> B >> K;
  int i=0;
  while (K>i) {
    if (i%2==0) {
      B+=A/2;
      A/=2;
      i++;
    }
    else {
      A+=B/2;
      B/=2;
      i++;
    }
  }
  cout << A << " " << B << endl;
}
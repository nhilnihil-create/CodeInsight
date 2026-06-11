#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,C,K;
  cin >> A >> B >> C >> K;
  if (K%2 == 1 && B-A < 1000000000000000000) {
    cout << B-A <<endl;
  }
  else if (A-B < 1000000000000000000) {
    cout << A-B <<endl;
  }
  else {
    cout << "unfair" <<endl;
  }
  
}

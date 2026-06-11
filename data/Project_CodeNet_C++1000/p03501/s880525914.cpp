#include <bits/stdc++.h>
using namespace std;
  int N,A,B ;
  int main() {
    cin >> N >> A >> B;
    if (N * A == B) {
  cout << B << endl;
}
else if (N * A >= B) {
  cout << B << endl;
}
else if (N * A <= B) {
  cout << N * A << endl;
  }
return 0;
  }
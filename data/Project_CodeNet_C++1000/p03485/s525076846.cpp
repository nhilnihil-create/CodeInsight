#include <bits/stdc++.h>
using namespace std;

int main() {
  double a,b, epsilon;
  epsilon = 0.000000000001;
  cin >> a >> b;
  int mean = (a+b-epsilon)/2 + 1;
  cout << mean << endl;
}
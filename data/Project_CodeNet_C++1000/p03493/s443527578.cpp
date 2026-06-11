#include <bits/stdc++.h>
using namespace std;

int main() {
  int s1s2s3, x, y, z;
  
  cin >> s1s2s3;
  x = s1s2s3 / 100;
  y = (s1s2s3 - 100 * x) / 10;
  z = s1s2s3 % 10;
  cout << x + y + z << endl;
}
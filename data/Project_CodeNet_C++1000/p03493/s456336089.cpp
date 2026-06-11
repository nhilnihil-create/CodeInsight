#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, s1, s2, s3;
  cin >> x;
  s1 = x / 100;
  s2 = (x % 100) / 10;
  s3 = (x % 100) % 10;
  
  cout << s1 + s2 + s3 << endl;
}
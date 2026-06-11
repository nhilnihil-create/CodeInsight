#include <bits/stdc++.h>
using namespace std;


int main() {
  int a;
  int s1;
  int s2;
  int s3;
  cin >> a;
  s1 = a / 100;
  s2 = a / 10;
  if (s2 > 9){
  s2 = s2 - 10;
  }
  s3 = a - 100 * s1 - 10 * s2;
  cout << s1 + s2 + s3 << endl;
}
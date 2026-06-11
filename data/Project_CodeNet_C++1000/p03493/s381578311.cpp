#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,s1,s2,s3;
  cin >> a;
  
  s1 = a / 100;
  s2 = a / 10 - s1 * 10;
  s3 = a - s1 * 100 - s2 * 10;
  
  cout << s1 + s2 + s3 << endl;
  // cout << s2 << endl;
  // cout << s3 << endl;

}
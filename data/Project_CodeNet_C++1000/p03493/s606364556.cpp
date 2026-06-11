#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int S, s1, s2, s3;
  cin >> S;
  s3 = S % 10;
  s2 = (S - s3) % 100 / 10;
  s1 = (S - s2 - s3) / 100;
  cout << s1 + s2 + s3 << endl;
}
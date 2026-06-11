#include <bits/stdc++.h>
using namespace std;

int main(){
  int S, s1, s2, s3;
  int count = 0;
  cin >> S;
  s1 = S / 100;
  s2 = (S - s1 * 100) / 10;
  s3 = S % 10;
  cout << s1 + s2 + s3 << endl;
}
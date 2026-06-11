#include <bits/stdc++.h>
using namespace std;

int main() {
  int S;
  cin >> S;
  int s1 = S / 100;
  int s2 = (S % 100) / 10;
  int s3 = (S % 100) % 10;
  cout << s1 + s2 + s3 << endl;
}
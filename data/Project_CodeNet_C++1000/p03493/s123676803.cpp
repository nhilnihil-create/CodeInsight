#include <bits/stdc++.h>
using namespace std;

int main() {
  int s1s2s3;
  cin >> s1s2s3;
  int t1 = s1s2s3 / 100;
  int t2 = (s1s2s3 - s1s2s3 / 100 * 100) / 10;
  int t3 = s1s2s3 - s1s2s3 / 100 * 100 - (s1s2s3 - s1s2s3 / 100 * 100) / 10 *10;
  cout << t1 + t2 + t3 << endl;
}
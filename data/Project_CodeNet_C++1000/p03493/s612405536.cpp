#include <bits/stdc++.h>
using namespace std;

int main() {
  int s1s2s3;
  cin >> s1s2s3;
  int k1 = s1s2s3 / 100;
  int k2 = (s1s2s3 - k1 * 100) / 10;
  int k3 = s1s2s3 - k1 * 100 - k2 *10;
  cout << k1 + k2 + k3 << endl;
}

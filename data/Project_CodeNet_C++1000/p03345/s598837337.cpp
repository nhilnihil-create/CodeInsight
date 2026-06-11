#include <bits/stdc++.h>
using namespace std;
int main () {
  long A, B, C, K;
  cin >> A >> B >> C >> K;
  cout << (K % 2 == 0?A-B:B-A) << endl;
  return 0;
}
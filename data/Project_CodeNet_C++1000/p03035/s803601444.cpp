#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  if (A > 12) cout << B;
  else if (A > 5) cout << B / 2;
  else cout << 0;
}
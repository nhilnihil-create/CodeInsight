#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, a;
  cin >> n >> k;
  a=1;
  for(i=0;i<n;i++) {
    if(a * 2 < a + k) {
      a *= 2;
    }
    else {
      a += k;
    }
  }
  cout << a << endl;
  return 0;
}
    
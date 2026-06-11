#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n;
  k = n;
  int x = 10,t = 0;
  for (int i = 0; i < 8; i++) {
    t += n % 10;
    n /= 10;
  }
  if (k % t == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
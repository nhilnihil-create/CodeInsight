#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (a >= 500) {
    cout << "Yes" << endl;
    return 0;
  }
  if ((n % 500) <= (a % 500)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
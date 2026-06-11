#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  if((n % 2 == 0 && n >= 2 * k) || (n % 2 == 1 && n + 1 >= 2 * k)) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}
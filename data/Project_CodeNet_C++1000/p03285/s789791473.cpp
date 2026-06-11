#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool flag = false;
  for (int i = 0; i <= n/7; i++) {
    if ((n - 7*i) % 4 == 0) flag = true;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
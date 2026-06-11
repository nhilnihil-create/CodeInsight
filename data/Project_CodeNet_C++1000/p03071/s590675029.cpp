#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (max(a, b) - min(a,b) >= 2){
    cout << 2 * max(a, b) - 1 << endl;
  }
  else {
    cout << a + b << endl;
  }
}

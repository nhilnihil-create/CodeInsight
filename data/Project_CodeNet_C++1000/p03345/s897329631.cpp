#include <bits/stdc++.h>

using namespace std;

int main(){
 long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2 == 0) {
    cout << a - b << '\n';
  } else {
    cout << b - a << '\n';
  }
  return 0;
}


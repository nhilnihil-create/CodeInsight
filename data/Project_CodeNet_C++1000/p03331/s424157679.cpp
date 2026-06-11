#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  cin >> n;
  int cont = 0;

  if(n % 10 == 0) cout << 10 << endl;
  else {
    while(n > 0) {
      cont += n % 10;
      n /= 10;
    }
    cout << cont << endl;
  }

  return 0;
}
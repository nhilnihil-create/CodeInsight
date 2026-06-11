#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  cin >> n;
  int aux = n;

  if(aux & 1) {
    aux++;
  }

  while(!(aux % 2 == 0 && aux % n == 0)) {
    aux += 2;
  }

  cout << aux << endl;

  return 0;
}
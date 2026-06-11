#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;

  cin >> a >> b;

  int minimo = min(a, b);
  int maximo = max(a, b);

  for(int i = minimo; i <= maximo; i++) {
    if((a*b*i) & 1) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";

  return 0;
}
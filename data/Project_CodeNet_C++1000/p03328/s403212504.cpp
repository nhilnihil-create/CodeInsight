#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  cin >> a >> b;

  int west = 1;

  // x is the east tower
  for (int x = 2; x <= 999; ++x) {
    int east = west + x;

    if (west - a == east - b) {
      cout << west - a << "\n";
      return 0;
    } else west = east;
  }

  return 1;
}

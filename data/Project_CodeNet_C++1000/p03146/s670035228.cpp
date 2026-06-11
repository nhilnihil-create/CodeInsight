#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a, i = 1;
  cin >> a;

  while (a != 4 && a != 2 && a != 1) {
    if (a & 1)
      a = 3 * a + 1;
    else
      a /= 2;
    i++;
  }
  cout << i + 3 << endl;
}
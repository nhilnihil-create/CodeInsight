#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  int x = 0;
  cin >> n >> a >> b;
  if (n*a<b) {
    x = n*a;
  } else {
    x = b;
  }
  cout << x << endl;
}
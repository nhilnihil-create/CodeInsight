#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n;
  cin >> n >> a >> b;
  
  int p1 = a * n;
  int p2 = b;

  if (p1 >= p2) {
    cout << p2 << endl;
  } else {
    cout << p1 << endl;
  }
}
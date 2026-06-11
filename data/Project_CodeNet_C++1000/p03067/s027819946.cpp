#include <bits/stdc++.h>
using namespace std;

int a, b, x;
int main() {
  cin >> a >> b >> x;
  if (a > b) swap(a, b);
  cout << (x >= a && x <= b ? "Yes" : "No") << endl;
}

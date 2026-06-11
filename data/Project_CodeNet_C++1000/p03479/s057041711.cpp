#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  long double x, y;
  cin >> x >> y;
  cout << floor(log2(y / x) + 1);
}
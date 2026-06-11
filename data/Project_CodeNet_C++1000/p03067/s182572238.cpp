#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) {
    swap(a, b);
  }
  puts(a < c && c < b ? "Yes" : "No");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> MA;
  int a;
  while (cin >> a) {
    MA[a]++;
    if (MA[a] > 2) return cout << "NO" << "\n", 0;
  }
  cout << "YES" << "\n";
}
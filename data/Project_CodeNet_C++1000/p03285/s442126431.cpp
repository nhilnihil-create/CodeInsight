#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n; cin >> n;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      if (i*4 + j*7 == n) {
        cout << "Yes\n";
        return 0;
      }
    }
  } 
  cout << "No\n";
}

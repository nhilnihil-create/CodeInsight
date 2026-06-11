#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (4 * i + 7 * j == n) {
        cout << "Yes\n";
        return 0;
      }
    }
  } 
  cout << "No\n";
  return 0;
}
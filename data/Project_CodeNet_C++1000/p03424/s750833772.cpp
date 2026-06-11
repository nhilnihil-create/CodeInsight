#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    char c; cin >> c;

    if (c == 'Y') {
      cout << "Four" << "\n";
      return 0;
    }
  }
  cout << "Three" << "\n";
}

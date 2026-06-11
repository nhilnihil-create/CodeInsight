#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  
  vector<int> choko(n);
  for (int i = 0; i < n; i++) {
    cin >> choko.at(i);
  }
  
  int count = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; ; j++) {
      if (j * choko.at(i) + 1 <= d) {
        count++;
      }
      else {
        break;
      }
    }
  }
  cout << x + count << endl;
}
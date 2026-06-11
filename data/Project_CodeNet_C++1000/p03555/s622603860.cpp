#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  string b;
  cin >> a >> b;
  int x = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[a.size()-i-1]) {
      x++;
      break;
    }
  }
  if (x == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  char s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == 'Y') {
      cout << "Four" << endl;
      break;
    }
  }
  
  if (s != 'Y') {
    cout << "Three" << endl;
  }
}
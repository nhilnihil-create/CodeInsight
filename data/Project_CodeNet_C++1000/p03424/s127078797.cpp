#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    char  col;
    cin >> col;
    if (col == 'Y') {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}
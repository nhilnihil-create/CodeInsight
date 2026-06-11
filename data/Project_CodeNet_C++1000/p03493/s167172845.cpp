#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  
  if (s == 0) cout << 0 << endl;
  else if (s % 3 == 1) cout << 1 << endl;
  else if (s % 3 == 2) cout << 2 << endl;
  else cout << 3 << endl;
  
}

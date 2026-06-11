#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int a = x / 1000;
  int b = (x / 100) % 10;
  int c = (x / 10) % 10;
  int d = x % 10;

  if (a == b && b == c) cout << "Yes" << endl;
    
  else if (b == c && c == d) cout << "Yes" << endl;
  
  else cout << "No" << endl;
}


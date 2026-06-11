#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  
  cin >> a;
  cin >> b;
  
  int p = a * b;
  
  if ((p / 2 * 2) == p) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  
  return 0;
}

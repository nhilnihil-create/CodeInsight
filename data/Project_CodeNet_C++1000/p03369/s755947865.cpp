#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  
  int topping = 0;
  for (int i = 0; i < 3; i++) {
    if (s.at(i) == 'o')
      topping += 100;
  }
  
  cout << 700 + topping << endl;
  
  return 0;
}
         
#include <bits/stdc++.h>

using namespace std;

int main() {
  string n;
  cin >> n;
  
  for (char i : n) {
  	int digit = i - 48;
    
    if (digit == 9)
      cout << "1";
     else if (digit == 1)
       cout << "9";
  }
  
  cout << "\n";
  
  return 0;
}
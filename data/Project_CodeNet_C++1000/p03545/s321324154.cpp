#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s[0] - '0';
  int b = s[1] - '0';
  int c = s[2] - '0';
  int d = s[3] - '0';
  
  for (int bit = 0; bit < (1<<3); bit++) {
    int sum = a;
    
    if (bit & 1) sum += b;
    else sum -= b;
    
    if (bit & (1<<1)) sum += c;
    else sum -= c;
    
    if (bit & (1<<2)) sum += d;
    else sum -= d;
    
    if (sum == 7) {
      cout << a;
      
      if (bit & 1) cout << '+';
      else cout << '-';
      
      cout << b;
      
      if (bit & (1<<1)) cout << '+';
      else cout << '-';
      
      cout << c;
      
      if (bit & (1<<2)) cout << '+';
      else cout << '-';
      
      cout << d << "=7";
     
      break;
    }
  }
}

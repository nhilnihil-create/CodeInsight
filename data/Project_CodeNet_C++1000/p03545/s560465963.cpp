#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  string a;
  cin >> a;
  
  for(int s= 0; s < 8; s++) {
    int total = a[0] - '0';
    string totalText;
    totalText += a[0];
    for(int i = 0; i < 3; i++){
        if((s >> i) & 1) {
          total += a[i+1] - '0';
          string partText;
          partText += "+";
          partText += a[i+1];
          totalText += partText;
        } else {
          total -= a[i+1] - '0';
          string partText;
          partText += "-";
          partText += a[i+1];
          totalText += partText;
        }
    }
    if (total == 7) {
      cout << totalText << "=7" << endl;
      break;
    }
  }
 
}

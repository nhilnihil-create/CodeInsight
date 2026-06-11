#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string ans = "Three";
  
  for (int i = 0; i < n; i++) {
    string si;
    cin >> si;
    
    if (si == "Y") {
      ans = "Four";
      break;
    }
  }
  
  cout << ans << endl;
}

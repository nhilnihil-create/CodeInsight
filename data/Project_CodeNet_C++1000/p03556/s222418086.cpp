#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  int s = 1;
  int ans;
  
  if (n == 1){
    cout << 1;
  }
  
  for (int i = 0; i < n; i++) {
    ans = s*s;
    if (ans > n){
      cout << (s-1)*(s-1);
      break;
    }
    s++;
  }
  
}

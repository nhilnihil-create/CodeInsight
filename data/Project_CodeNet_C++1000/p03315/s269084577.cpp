#include <bits/stdc++.h>
using namespace std;

int main() {
  
  char s[5];
  cin >> s;
  
  int ans = 0;
  
  for (int i = 0; i < 4; i++) {
    if(s[i] == '+') ans++;
    else ans--;
  }
  
  cout << ans << endl;
}
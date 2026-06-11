#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x = 0;
  string st;
  
  cin >> n >> st;
  
  for (int i = 0; i < n; ++i) {
    if(st[i] == 'R') 
      ++ x;
    else 
      -- x;
  }
  
  if(x > 0)
    puts("Yes");
  else 
    puts("No");
  
  return 0;
}
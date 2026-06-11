#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  s.insert(n);
  
  int x = 0;
  for(int i=2; ; i++) {
    if(n%2 == 0) n /= 2;
    else n = 3*n + 1;
    x = s.size();
    s.insert(n);
    if(x == s.size()) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
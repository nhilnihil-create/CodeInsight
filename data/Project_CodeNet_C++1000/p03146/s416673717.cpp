#include<bits/stdc++.h>
using namespace std;
int main() {
  int s; cin >> s;
  set<int> fn;
  fn.insert(s);
  int m, next;
  for(int i = 1; i <= 1000000; i++) {
    if(s % 2 == 0) {
      next = s /2;
    }
    else {
      next = s *3 +1;
    }
    if(fn.count(next)) {
      m = i+1;
      break;
    }
    else {
      fn.insert(next);
      s = next;
    }
  }
  cout << m << endl;
}
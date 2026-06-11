#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  auto chk = [](int n) {
    string ns = to_string(n);
    bool ans = true;
    for (int i = 0; i < ns.size(); i++) {
      if (ns[i] != ns[0]) {
        ans = false;
        break;
      }
    }
    
    return ans;
  };
  
  while (!chk(n)) {
    n++;
  }
  
  cout << n << '\n';
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }
  
  cin >> m;
  vector<string> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t.at(i);
  }
  
  int a = 0, b = 1;
  string str;
  
  for (int i = 0; i < n; i++, b = 1) {
    
    //青いカードを確かめる
    for (int j = 0; j < n; j++) {
      if (i != j && s.at(i) == s.at(j)) {
        b++;
      }
    }
    
    //赤いカードを確かめる
    for (int k = 0; k < m; k++) {
      if (s.at(i) == t.at(k)) {
        b--;
      }
    }
    
    if (b > a) {
      a = b;
    }
  }
  
  cout << a << endl;
  
}
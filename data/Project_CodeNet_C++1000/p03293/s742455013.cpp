#include<bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  for(int i=0; i<n; i++) {
    bool f = true;
    for(int j=0; j<n; j++) {
      int temp = i+j;
      if(temp >= n) {
        temp -= n;
      }
      if(s.at(j) != t.at(temp)) {
        f = false;
      }
    }
    if(f) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
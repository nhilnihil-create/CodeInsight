#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string s;
  cin >> s;
  string k = "keyence";
  int n = s.size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<n-i; j++) {
      string t = s;
      if(t.erase(i,j) == k) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  set<string> x;
  x.insert(s);
  
  int l;
  string a, b;
  for(int i=0; i<n-1; i++) {
    cin >> a;
    if(i==0) {
      if(s[s.size()-1] != a[0]) {
        cout << "No" << endl;
        return 0;
      }
    }
    else if(b[b.size()-1] != a[0]) {
      cout << "No" << endl;
      return 0;
    }
    b = a;
    l = x.size();
    x.insert(a);
    if(l == x.size()) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
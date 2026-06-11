#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  string s;
  cin >> n;
  int i;
  for (i=0; i<n; i++) {
    cin >> s;
    if (s=="Y") {
      cout << "Four" << endl;
      break;
    }
    else if (i==n-1 && s!="Y") {
      cout << "Three" << endl;
    }
  }
}
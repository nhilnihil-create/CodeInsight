//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//char s[100001];
string s;
int main() {
  int n, q, k;
  cin >> n;
  cin >> s;
  cin >> q;
  while(q--) {
    long d=0, m=0, dm=0, dmc=0;
    cin >> k;
    for (int i=0; i<n; i++) {
      if (i>=k) {
        if (s[i-k] == 'D') {
          d--;
          dm -= m;
        } else if (s[i-k] == 'M')
          m--;
      }
      if (s[i] == 'D')
        d++;
      else if (s[i] == 'M') {
        m++;
        dm += d;
      } else if (s[i] == 'C')
        dmc += dm;
    }
    cout << dmc << "\n";
  }
}

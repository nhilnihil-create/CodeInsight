#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  int count = 0, maxv = 0;

  rep(i, s.length()) {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
        count++;
        maxv = max(count, maxv);
    } else {
        count = 0;
    }
  }
  
  cout << maxv << endl;

  return 0;
}

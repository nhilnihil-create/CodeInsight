#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j, cnt, max;
  string s;
  cin >> s;
  max = INT_MIN;
  for (i = 0; i < s.length(); i++) {
    cnt = 0;
    for (j = i; j < s.length(); j++) {
      if (s[j] == 'A' || s[j] == 'T' || s[j] == 'G' || s[j] == 'C')
        cnt++;
      else
        break;
    }
    if (cnt > max) max = cnt;
  }

  cout << max << endl;
}
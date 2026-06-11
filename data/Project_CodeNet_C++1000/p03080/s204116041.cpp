#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string s;
  cin >> N >> s;
  int b = 0,r = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'B') {
      b++;
    } else if (s[i] == 'R') {
      r++;
    }
  }
  if (r > b) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
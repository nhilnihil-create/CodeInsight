#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int a = 0, b = 0, c = 0;
  string s;
  cin >> s;
  rep(i,3)
    if (s[i] == 'a') {
      a++;
    } else if (s[i] == 'b') {
      b++;
    } else {
      c++;
    }
  if (a == 1 && b == 1 && c == 1)
    cout << "Yes";
  else
    cout << "No";
}

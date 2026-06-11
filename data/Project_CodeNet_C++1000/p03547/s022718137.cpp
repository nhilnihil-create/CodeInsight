#include <bits/stdc++.h>
using namespace std;
int main()
{
  char x, y;
  cin >> x >> y;

  string s = "ABCDEF";
  int k = 9;
  for (int i = 0; i < 6; i++) {
    if (s[i] == x) k += i;
  }
  int l = 9;
  for (int j = 0; j < 6; j++) {
    if (s[j] == y) l += j;
  }

  if (k < l) cout << '<' << endl;
  else if (k > l) cout << '>' << endl;
  else cout << '=' << endl;

  return 0;
}

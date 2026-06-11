#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, x;
  cin >> a >> b >> x;

  string s = "NO";
  for (int i = 0; i < x; i++) {
    if (a + b >= x && a <= x) {
      s = "YES";
    }
  }

  cout << s << endl;

  return 0;
}

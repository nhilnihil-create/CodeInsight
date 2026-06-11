#include <bits/stdc++.h>
using namespace std;

int main () {
  char x,y;
  cin >> x >> y;
  int a=x-55,b=y-55;

  if (x<y) cout << "<" << endl;
  else if (x>y) cout << ">" << endl;
  else cout << "=" << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  string ans="No";
  if (abs(a-c)<=d) {ans="Yes";}
  if (abs(a-b)<=d && abs(b-c)<=d) {ans="Yes";}
  cout << ans << endl;
}

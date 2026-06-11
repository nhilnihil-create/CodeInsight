#include <bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  int d1,d2,d3;
  if (a<b) d1=b-a;
  else d1=a-b;

  if (b<c) d2=c-b;
  else d2=b-c;

  if (a<c) d3=c-a;
  else d3=a-c;

  bool dd=true;
  if (d1>d) dd=false;
  if (d2>d) dd=false;

  if (dd || d3<=d) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

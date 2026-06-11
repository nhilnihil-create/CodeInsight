#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,n;
  cin >> a >> b >> c >> d;
  n=0;
  if (a>b) n+=b;
  else n+=a;
  if (c>d) n+=d;
  else n+=c;
  cout << n << endl;
}
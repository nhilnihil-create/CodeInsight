#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
int main() {
  int a, b, c, d ;
  cin >> a >> b >> c >> d;
  int ab, cd;
  if (a > b) ab = b;
  else ab = a;
  if (c > d) cd = d;
  else cd = c;
  cout << ab+cd << endl;
  return 0;
}
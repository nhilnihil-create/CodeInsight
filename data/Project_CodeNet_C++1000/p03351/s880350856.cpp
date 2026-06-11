#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
int main() {
  int a, b, c, d ;
  cin >> a >> b >> c >> d;
  int ab = abs(a-b);
  int bc = abs(b-c);
  if (abs(a-c) <= d) cout << "Yes" << endl;
  else if (ab > d || bc > d) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
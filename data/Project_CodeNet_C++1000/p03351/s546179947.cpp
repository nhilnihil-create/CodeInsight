#include <bits/stdc++.h>
using namespace std;

int f(int x, int y) {
  if (x>y) return x-y;
  else return y-x;
}
int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if (f(a,c)<=d) cout << "Yes" << endl;
  else if (f(a,b)<=d && f(b,c)<=d) cout << "Yes" << endl;
  else cout << "No" << endl;
}
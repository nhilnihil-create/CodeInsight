#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int c,d;
  c = min(a,b);
  if(n < a+b) d = a+b-n;
  else d = 0;
  cout << c << " " << d << endl;
  return 0;
}
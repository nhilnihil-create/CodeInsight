#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  int wa = a + b;
  int sa = a - b;
  int zyo = a * b;
  
  if(wa > sa && wa > zyo) cout << wa;
  else if(sa > wa && sa > zyo) cout << sa;
  else if(zyo > wa && zyo > sa) cout << zyo;
  else cout << wa;
}

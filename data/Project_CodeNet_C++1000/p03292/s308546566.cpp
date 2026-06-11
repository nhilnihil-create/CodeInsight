#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c; cin >> a >> b >> c;
  int d, e, f;
  d = abs(b-a); e = abs(c-b); f = abs(a-c);
  cout << min(d+e, min(e+f, f+d)) << endl;
}
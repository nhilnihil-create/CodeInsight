#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  bool ok = false;
  if(abs(a-c) <= d) ok = true;
  else if(abs(a-b) <= d && abs(b-c) <= d) ok = true;
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
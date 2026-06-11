#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  int intx, inty;
  if(x == "A") intx = 10;
  else if(x == "B") intx = 11;
  else if(x == "C") intx = 12;
  else if(x == "D") intx = 13;
  else if(x == "E") intx = 14;
  else if(x == "F") intx = 15;
  if(y == "A") inty = 10;
  else if(y == "B") inty = 11;
  else if(y == "C") inty = 12;
  else if(y == "D") inty = 13;
  else if(y == "E") inty = 14;
  else if(y == "F") inty = 15;
  
  if(intx < inty) cout << "<" << endl;
  else if(intx > inty) cout << ">" << endl;
  else cout << "=" << endl;
  
  return 0;
}

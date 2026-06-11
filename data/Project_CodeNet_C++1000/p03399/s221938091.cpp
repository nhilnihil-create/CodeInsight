#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int res = 0;
  if(a < b) res += a;
  else res += b;
  if(c < d) res += c;
  else res += d;
  cout << res << endl;
  return 0;
}
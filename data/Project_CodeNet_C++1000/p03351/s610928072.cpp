#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool ans = false;
  if(abs(a-c) <= d) ans = true;
  else if(abs(a-b) <= d && abs(c-b) <= d) ans = true;

  puts(ans?"Yes":"No");
}

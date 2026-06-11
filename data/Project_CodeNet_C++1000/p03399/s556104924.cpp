#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << min(a,b) + min(c,d) << endl;
  return 0;
}
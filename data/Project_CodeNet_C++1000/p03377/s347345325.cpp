#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x;

  cin >> a >> b >> x;

  if(x < a || x > (a+b)) cout << "NO\n";
  else cout << "YES\n";  

  return 0;
}
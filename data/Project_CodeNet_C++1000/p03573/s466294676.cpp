#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c;
  cin >> a >> b >> c;

  if (a != b & a != c) cout << a << "\n";
  else if (b != a && b != c) cout << b << "\n";
  else cout << c << "\n";
}

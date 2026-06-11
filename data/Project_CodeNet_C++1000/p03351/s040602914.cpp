#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

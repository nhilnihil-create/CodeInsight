#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int d, n;
  cin >> d >> n;

  int base = static_cast<int>(pow(100, d));
  int res = base * n;

  if (n == 100) res += base;
  cout << res << "\n";
}

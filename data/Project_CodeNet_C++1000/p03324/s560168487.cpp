#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int d, n;
  cin >> d >> n;

  if (n == 100) cout << static_cast<int>(pow(100, d) * (n + 1))  << "\n";
  else cout << static_cast<int>(pow(100, d) * n) << "\n";
}

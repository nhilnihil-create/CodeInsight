#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, k;
  cin >> a >> b >> k;

  for (int i = a; i <= min(b, a + k - 1); ++i) cout << i << "\n";
  for (int i = max(b - k + 1, a + k); i <= b; ++i) cout << i << "\n";
}

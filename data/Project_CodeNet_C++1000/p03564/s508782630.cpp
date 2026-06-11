#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k;
  cin >> n >> k;

  int res = 1;
  for (int i = 0; i < n; ++i) {
    if (res * 2 < res + k) res *= 2;
    else res += k;
  }
  cout << res << "\n";
}

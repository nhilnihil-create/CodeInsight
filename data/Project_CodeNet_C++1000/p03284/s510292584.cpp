#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  int ans = min(1,n%k);
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(i+k-1 <= n) ans++;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int ans = 0;
  if(a == b) ans = 2 * a;
  else if(a > b) ans = 2 * a - 1;
  else ans = 2 * b - 1;
  
  cout << ans << endl;
  
  return 0;
}

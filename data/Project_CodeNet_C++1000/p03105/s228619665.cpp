#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min(c, b/a);
  cout << ans << endl;
  
  
  return 0;
}

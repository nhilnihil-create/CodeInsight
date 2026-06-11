#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = a*n;
  if(ans < b )cout << ans << endl;
  else if(ans > b)cout << b << endl;
  else cout << ans << endl;
}
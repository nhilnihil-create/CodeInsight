#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
 
    int mx = max({a, b, c});
    int ans = a + b + c + 9 * mx;

    cout << ans;

   return 0;
}
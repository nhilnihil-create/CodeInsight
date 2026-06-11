#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


int main() {
  int a,b;
  cin >> a >> b;
  int ans;
  ans += a-1;
  if(a <= b) ans += 1;

  cout << ans << endl;
}

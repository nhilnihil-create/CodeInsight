#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  string ans;
  ans = (a <= 8 && b <= 8) ? "Yay!":":(";
  cout << ans << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);

int main() {
  ll X, Y;
  cin >> X >> Y;

  ll cur = X;
  int ans = 0;

  while (cur <= Y){
    ans++;
    cur *= 2;
  }

  cout << ans << endl;
}

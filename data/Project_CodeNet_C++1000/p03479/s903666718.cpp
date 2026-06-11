#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll X,Y;
  cin >> X >> Y;
  int ans = 0;
  while (X <= Y) {
    X *= 2;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
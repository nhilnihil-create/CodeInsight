#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll X,Y;
  cin >> X >> Y;
  if (X % Y == 0) {
    cout << -1 << endl;
  } else {
    cout << X << endl;
  }
  return 0;
}

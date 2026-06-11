#include <iostream>
#include <climits>

using namespace std;

int main() {
  int n , bt;
  cin >> n >> bt;
  int ans = INT_MAX;
  int c, t;
  while (cin >> c >> t)
    if (t <= bt)
      ans = min(ans, c);

  if (ans == INT_MAX)
    cout << "TLE" << endl;
  else
    cout << ans << endl;
}

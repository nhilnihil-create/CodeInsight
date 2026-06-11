#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> left_west(n+1,0); // iより左にWが何個あるか
  for (int i = 1; i < n; i++) {
    left_west[i] = left_west[i-1];
    if (s[i-1] == 'W') {
      left_west[i]++;
    }
  }
  vector<int> right_east(n+1,0); // iより右にEが何個あるか
  for (int i = n-2; i >= 0; i--) {
    right_east[i] = right_east[i+1];
    if (s[i+1] == 'E') {
      right_east[i]++;
    }
  }
  int ans = 300005;
  for (int i = 0; i < n; i++) {
    ans = min(ans, left_west[i] + right_east[i]);
  }
  cout << ans << endl;
  return 0;
}
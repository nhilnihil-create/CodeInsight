#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> h;
 
int solve();
 
int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    h.push_back(x);
  }
  sort(h.begin(), h.end());
  cout << solve() << endl;
  return 0;
}
 
int solve() {
  int ans = 2000000000;
  for(int i = 0; i + k - 1 < n; ++i)
    ans = min(ans, h[i + k - 1] - h[i]);
  return ans;
}
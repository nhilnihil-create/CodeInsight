#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vi(n);
  vector<int> ci(n);
  for (int i = 0; i < n; i++) cin >> vi.at(i);
  for (int i = 0; i < n; i++) cin >> ci.at(i);
  
  int ans = 0;
  for (int i = 0; i < (1<<n); i++) {
    vector<int> index;
    for (int j = 0; j < n; j++) {
      if (i & (1<<j)) index.push_back(j);
    }
    int x = 0;
    int y = 0;
    for (int j = 0; j < index.size(); j++) {
      x += vi.at(index.at(j));
      y += ci.at(index.at(j));
    }
    ans = max(ans,x-y);
  }
  cout << ans << endl;
}
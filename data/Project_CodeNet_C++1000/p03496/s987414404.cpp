#include <bits/stdc++.h>
using namespace std;

int n, mnum = 0, num = 0;
int a[55] = {0};
vector<pair<int, int>> ans;

void solve();

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  solve();
  return 0;
}

void solve() {
  for(int i = 0; i < n; ++i)
    if(abs(mnum) < abs(a[i])) mnum = a[i], num = i;
  for(int i = 0; i < n; ++i)
    if(mnum != a[i]) {
      ans.push_back(make_pair(num, i));
      a[i] += mnum;
    }
  if(mnum > 0) {
    for(int i = 1; i < n; ++i)
      if(a[i - 1] > a[i]) {
        ans.push_back(make_pair(i - 1, i));
        a[i] += a[i - 1];
      }
  }
  else {
    for(int i = n - 1; i >= 1; --i)
      if(a[i - 1] > a[i]) {
        ans.push_back(make_pair(i, i - 1));
        a[i - 1] += a[i];
      }
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); ++i)
    cout << ans[i].first + 1 << " " << ans[i].second + 1
         << endl;
}

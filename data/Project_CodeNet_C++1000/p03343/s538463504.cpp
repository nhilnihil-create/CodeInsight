#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin>>n>>k>>q;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  int b[n];
  for (int i=0; i<n; i++) b[i] = a[i];
  sort(b, b + n);
  set<int> sa;
  for (int i=0; i<n; i++) sa.insert(a[i]);
  int ans = b[q-1] - b[0];
  bool can_select[n];
  for (int i=0; i<n; i++) can_select[i] = true;
  for (int v: sa) {
    for (int i=0; i<n; i++) {
      if (a[i] == v) {
        can_select[i] = false;
      }
    }
    vector<int> nums;
    for (int i=0; i<n; i++) {
      if (!can_select[i]) {
        continue;
      }
      int start = i;
      while (i < n && can_select[i]) {
        ++i;
      }
      if (i - start + 1 < k) {
        continue;
      }
      vector<int> list;
      for (int j=start; j<i; j++) {
        list.push_back(a[j]);
      }
      sort(list.begin(), list.end());
      for (int j=0; j<i-start-(k-1); j++) {
        nums.push_back(list[j]);
      }
    }
    if (nums.size() < q) {
      break;
    }
    sort(nums.begin(), nums.end());
    ans = min(nums[q-1] - nums[0], ans);
  }
  cout<<ans<<endl;
}
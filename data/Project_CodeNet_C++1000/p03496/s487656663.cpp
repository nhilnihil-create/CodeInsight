#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int abMax = 0;
  int value = 0;
  int idx = -1;
  for(int i=0;i<n;i++) {
    if(abs(a[i]) > abMax) {
      abMax = abs(a[i]);
      value = a[i];
      idx = i;
    }
  }
  if(idx == -1) {
    cout << 0 << endl;
    return 0;
  }
  vector<P> ans;
  for(int i=0;i<n;i++) {
    if(a[i] == value) continue;
    else {
      P p;
      p.first = i+1; p.second = idx+1;
      ans.emplace_back(p);
      a[i] += value;
    }
  }
  if(value < 0) {
    for(int i=n-2;i>=0;i--) {
      if(a[i] <= a[i+1]) continue;
      else {
        ans.emplace_back(make_pair(i+1, i+2));
        a[i] += a[i+1];
      }
    }
  }
  else {
    for(int i=0;i<n-1;i++) {
      if(a[i] <= a[i+1]) continue;
      else {
        ans.emplace_back(make_pair(i+2, i+1));
        a[i+1] += a[i];
      }
    }
  }
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) {
    cout << ans[i].second << " " << ans[i].first << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  pair<int, int> r[n], b[n];
  for (int i=0; i<n; i++) cin>>r[i].first>>r[i].second;
  for (int i=0; i<n; i++) cin>>b[i].first>>b[i].second;
  sort(r, r + n);
  sort(b, b + n);
  bool used[n];
  for (int i=0; i<n; i++) used[i] = false;
  int cnt = 0;
  for (int i=n-1; i>=0; i--) {
    bool found = false;
    int min_d = 200;
    int i_min_d = -1;
    for (int j=0; j<n; j++) {
      if (used[j]) {
        continue;
      }
      if (r[i].first < b[j].first && r[i].second < b[j].second) {
        found = true;
        if (b[j].second <= min_d) {
          min_d = b[j].second;
          i_min_d = j;
        }
      }
    }
    if (found) {
      used[i_min_d] = true;
      ++cnt;
    }
  }
  cout<<cnt<<endl;
}
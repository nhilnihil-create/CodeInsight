#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  vector<long long> b;
  vector<int> idx;
  int cnt = 0;
  for (int i=0; i<n; i++) {
    long long tmp = 0;
    for (int j=i; j<n; j++) {
      tmp += a[j];
      b.push_back(tmp);
      idx.push_back(cnt);
      ++cnt;
    }
  }

  long long ans = 0;
  for (int i=63; i>=0; i--) {
    if (idx.size() < k) {
      break;
    }
    vector<int> new_idx;
    for (int j: idx) {
      long long bj = b[j];
      if ((bj >> i) & 1) {
        new_idx.push_back(j);
      }
    }
    if (new_idx.size() >= k) {
      ans += pow(2, i);
      idx = new_idx;
    }
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int v[n];
  for (int i=0; i<n; i++) cin>>v[i];
  long long ans = -1e8;
  for (int left=0; left<=n; left++) {
    for (int right=0; left+right<=min(n, k); right++) {
      long long tmp = 0;
      vector<int> minus;
      for (int i=0; i<left; i++) {
        tmp += v[i];
        if (v[i] < 0) {
          minus.push_back(v[i]);
        }
      }
      for (int i=0; i<right; i++) {
        tmp += v[n-1-i];
        if (v[n-1-i] < 0) {
          minus.push_back(v[n-1-i]);
        }
      }
      sort(minus.begin(), minus.end());
      for (int i=0; i<k-(left+right); i++) {
        if (i >= minus.size()) {
          break;
        }
        tmp -= minus[i];
      }
      ans = max(tmp, ans);
    }
  }
  cout<<ans<<endl;
}
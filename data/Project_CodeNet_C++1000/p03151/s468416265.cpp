#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  long long int totalA = 0, totalB = 0;
  for(int i=0;i<n;++i) {
    cin >> a[i];
    totalA += a[i];
  }
  for(int i=0;i<n;++i) {
    cin >> b[i];
    totalB += b[i];
  }

  if(totalB > totalA) cout << -1 << endl;
  else {
    vector<int> surplus;
    long long int demand = 0;
    int ans = 0;
    for(int i=0;i<n;i++) {
      if(a[i] >= b[i]) surplus.emplace_back(a[i]-b[i]);
      else {
        ans++;
        demand += b[i] - a[i];
      }
    }

    sort(surplus.rbegin(), surplus.rend());
    for(int i=0;i<surplus.size();i++) {
      if(demand <= 0) break;
      else {
        demand -= surplus[i];
        ans++;
      }
    }

    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin >> n >> m;
  int k,a;
  vector<int> list(m+1);
  for(int i=0; i<n; i++) {
    cin >> k;
    for(int j=0; j<k; j++) {
      cin >> a;
      list.at(a) += 1;
    }
  }
  int ans = 0;
  for(int i=1; i<=m; i++) {
    if(list.at(i) == n) {
      ans++;
    }
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int64_t p[m], y[m];
  vector<int64_t> a[n+1];
  for(int i=0; i<m; i++){
    cin >> p[i] >> y[i];
    a[p[i]].push_back(y[i]);
  }
  for(int i=1; i<n+1; i++)
    sort(a[i].begin(), a[i].end());
    
  for(int i=0; i<m; i++){
    int64_t tmp = p[i]*1000000+distance(a[p[i]].begin(),lower_bound(a[p[i]].begin(), a[p[i]].end(), y[i]))+1;
    cout << setfill('0') << right << setw(12);
    cout << tmp << endl;
  }
  return 0;
}

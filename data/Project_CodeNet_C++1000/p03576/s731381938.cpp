#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans=4000000000000000010;
  cin >> n >> k;
  vector<vector<long>> xy(n,vector<long>(2));
  for(long i=0;i<n;i++) cin >> xy[i][0] >> xy[i][1];
  sort(xy.begin(),xy.end());

  for(long i=0;i<n;i++) {
    for(long j=i+k-1;j<n;j++) {
      vector<long> y;
      for(long i2=i;i2<=j;i2++) y.push_back(xy[i2][1]);
      sort(y.begin(),y.end());
      for(long i2=0;i2<=j-i+1-k;i2++) ans=min(ans,(xy[j][0]-xy[i][0])*(y[i2+k-1]-y[i2]));
    }
  }
  cout << ans << endl;
}
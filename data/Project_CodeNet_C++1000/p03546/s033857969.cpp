#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w,ans=0;
  cin >> h >> w;
  vector<vector<long>> c(10,vector<long>(10));
  vector<vector<long>> a(h,vector<long>(w));
  for(long i=0;i<10;i++) for(long j=0;j<10;j++) cin >> c[i][j];
  for(long i=0;i<h;i++) for(long j=0;j<w;j++) cin >> a[i][j];

  for(long i=0;i<10;i++) {
    for(long j=0;j<10;j++) {
      for(long k=0;k<10;k++) c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
    }
  }

  for(long i=0;i<h;i++) for(long j=0;j<w;j++) if(a[i][j]>-1) ans+=c[a[i][j]][1];

  cout << ans << endl;
}
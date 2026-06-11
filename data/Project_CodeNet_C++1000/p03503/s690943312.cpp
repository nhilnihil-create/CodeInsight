#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=-999999999999999;
  cin >> n;
  vector<vector<long>> f(n,vector<long>(10)),p(n,vector<long>(11));
  for(long i=0;i<n;i++) {
    for(long j=0;j<10;j++) {
      cin >> f[i][j];
    }
  }
  for(long i=0;i<n;i++) {
    for(long j=0;j<11;j++) {
      cin >> p[i][j];
    }
  }
  
  for(long bit=1;bit<(1<<10);bit++) {
    long bitans=0;
    for(long i=0;i<n;i++) {
      long eigyo=0;
      for(long j=0;j<10;j++) {
        if(f[i][j]==1&&(bit&(1<<j))) eigyo++;
      }
      bitans+=p[i][eigyo];
    }
    ans=max(ans,bitans);
  }
  cout << ans << endl;
}
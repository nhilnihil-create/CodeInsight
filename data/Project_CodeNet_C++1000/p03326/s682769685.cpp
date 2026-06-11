#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,m,ans=0;
  cin >> n >> m;
  vector<vector<long>> p(n,vector<long>(3)); 
  for(long i=0;i<n;i++) cin >> p[i][0] >> p[i][1] >> p[i][2];
  for(long i=0;i<8;i++) {
    vector<long> psum(n);
    for(long j=0;j<n;j++) {
      if(i&1) psum[j]+=p[j][0];
      else psum[j]-=p[j][0];
      if(i&2) psum[j]+=p[j][1];
      else psum[j]-=p[j][1];
      if(i&4) psum[j]+=p[j][2];
      else psum[j]-=p[j][2];
    }
    sort(psum.begin(),psum.end());
    reverse(psum.begin(),psum.end());
    long a=0;
    for(long j=0;j<m;j++) a+=psum[j];
    ans=max(ans,a);
  }
  cout << ans << endl;
}
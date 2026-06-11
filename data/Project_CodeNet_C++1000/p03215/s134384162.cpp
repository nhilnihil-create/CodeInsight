#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,k,ans=0;
  cin >> n >> k;
  vector<long> a(n),cum(n+1);
  multiset<long> ms,ms2;
  for(long i=0;i<n;i++) cin >> a[i];
  
  for(long i=0;i<n;i++) cum[i+1]=cum[i]+a[i];
  for(long i=0;i<n;i++) {
    for(long j=i+1;j<=n;j++) {
      ms.insert(cum[j]-cum[i]);
    }
  }
  for(long x=(1L<<40);x>=1;x/=2) {
    ms2=ms;
    long aaa=0;
    for(auto itr=ms2.begin();itr!=ms2.end();) {
      if((*itr)&x) {
        itr++;
      } else {
        ms2.erase(itr);
        aaa++;
        itr++;
      }
    }
    if(ms2.size()>=k) {
      ans+=x;
      ms=ms2;
    }
  }
  cout << ans << endl;
}
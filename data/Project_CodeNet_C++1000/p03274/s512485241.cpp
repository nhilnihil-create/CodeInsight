#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans=0;
  cin >> n >> k;
  vector<long> x(n),a,b;
  for(long i=0;i<n;i++) {
    cin >> x[i];
    if(x[i]>0) {
      a.push_back(x[i]);
    } else if(x[i]<0) {
      b.push_back(0-x[i]);
    } else {
      k--;
    }
  }
  reverse(b.begin(),b.end());
  if(k>0) {
    ans=9999999999999;
    for(long i=1;i<k;i++) {
      if(i<=a.size()&&k-i<=b.size()) ans=min(ans,min(a[i-1],b[k-i-1])*2+max(a[i-1],b[k-i-1]));
    }
    if(k<=a.size())ans=min(ans,a[k-1]);
    if(k<=b.size())ans=min(ans,b[k-1]);
  }
  cout << ans << endl;
}
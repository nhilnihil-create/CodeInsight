#include <bits/stdc++.h>
using namespace std;

int main() {
  long k,ans1=2,ans2=2;
  cin >> k;
  vector<long> a(k);
  for(long i=0;i<k;i++) cin >> a[i];
  for(long i=k-1;i>=0;i--) {
    ans1=(ans1+a[i]-1)/a[i]*a[i];
    ans2=ans2/a[i]*a[i];
    if(ans1>ans2) {
      ans1=-1;
      break;
    }
    ans2=ans2+a[i]-1;
  }
  if(ans1!=-1) cout << ans1 << " " << ans2 << endl;
  else cout << -1 << endl;
}
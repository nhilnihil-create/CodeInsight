#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n);
  for(long i=0;i<n;i++) {
    cin >> a[i];
    a[i]+=n-i;
  }
  sort(a.begin(),a.end());
  for(long i=0;i<n;i++) ans+=max(a[(n-1)/2]-a[i],a[i]-a[(n-1)/2]);
  cout << ans << endl;
}
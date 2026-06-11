#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,z,w,ans;
  cin >> n >> z >> w;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  ans=labs(a[n-1]-w);
  if(n>1) ans=max(ans,labs(a[n-2]-a[n-1]));
  cout << ans << endl;
}
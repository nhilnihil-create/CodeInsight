#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n),b(n);
  vector<pair<long,long>> c(n);
  for(long i=0;i<n;i++) {
    cin >> a[i] >> b[i];
    c[i]={a[i]+b[i],i};
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  for(long i=0;i<n;i++) {
    if(i%2==0) ans+=a[c[i].second];
    if(i%2==1) ans-=b[c[i].second];
  }
  cout << ans << endl;
}
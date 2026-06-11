#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,h,ans=0;
  cin >> n >> h;
  vector<long> a(n);
  vector<long> b(n);
  for(long i=0;i<n;i++) cin >> a[i] >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(long i=n-1;i>=0;i--) {
    if(b[i]<a.back()) break;
    ans++;
    h-=b[i];
    if(h<=0) break;
  }
  if(h>0) ans+=(h+a.back()-1)/a.back();
  cout << ans << endl;
}
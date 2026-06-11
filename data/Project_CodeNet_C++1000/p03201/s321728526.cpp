#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,xx=1;
  cin >> n;
  vector<long> a(n);
  map<long,long> mp;
  for(long i=0;i<n;i++) cin >> a[i];
  for(long i=0;i<31;i++) xx*=2;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(long i=0;i<n;i++) {
    bool b=true;
    long x=xx;
    while(x>a[i]&&b) {
      if(mp[x-a[i]]>0) {
        b=false;
        ans++;
        mp[x-a[i]]--;
      }
      x/=2;
    }
    if(b)mp[a[i]]++;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,ans;
  cin >> n;
  ans=n;
  map<long,long> mp;
  for(long i=0;i<n;i++) {
    cin >> a;
    mp[a]++;
    if(a==mp[a]) ans-=a;
  }
  cout << ans << endl;
}
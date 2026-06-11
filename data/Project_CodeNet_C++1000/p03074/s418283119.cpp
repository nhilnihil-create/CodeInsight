#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans;
  string s;
  vector<long> a;
  cin >> n >> k >> s;
  
  if(s[0]=='0') a.push_back(0);
  a.push_back(1);
  for(long i=1;i<n;i++) {
    if(s[i-1]==s[i]) a[a.size()-1]++;
    else a.push_back(1);
  }
  if(s[n-1]=='0') a.push_back(0);

  if(a.size()<=k*2+1) {
    ans=n;
  } else {
    long x=0;
    for(long i=0;i<k*2+1;i++) x+=a[i];
    ans=x;
    for(long i=0;i<(a.size()-k*2+1)/2;i++) {
      x-=a[i*2]+a[i*2+1];
      x+=a[k*2+i*2+1]+a[k*2+i*2+2];
      ans=max(ans,x);
    }
  }
  cout << ans << endl;
}
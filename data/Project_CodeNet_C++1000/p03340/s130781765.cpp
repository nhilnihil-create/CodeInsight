#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,x=0,y=0;
  cin >> n;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  for(long i=0;i<n;i++) {
    while((y^a[i])!=y+a[i]) y-=a[x],x++;
    ans+=i-x+1;
    y+=a[i];
  }
  cout << ans << endl;
}
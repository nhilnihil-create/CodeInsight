#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,ans=0;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++)cin >> b[i];
  for(int i=0;i<n;i++)cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  for(int i=0;i<n;i++)ans+=(lower_bound(a.begin(),a.end(),b[i])-a.begin())*(c.end()-upper_bound(c.begin(),c.end(),b[i]));
  cout << ans << endl;
}

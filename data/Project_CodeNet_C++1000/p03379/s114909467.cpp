#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,a;
  vector<int> x,y;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    x.push_back(a);
    y.push_back(a);
  }
  sort(x.begin(),x.end());
  for(int i=0;i<n;i++){
    if(x[n/2]<=y[i]) cout<<x[(n-1)/2]<<"\n";
    else cout<<x[(n+1)/2]<<"\n";
  }
  return 0;
}

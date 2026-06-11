#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,d=1001001001; cin>>n>>k;
  vector<int> h(n); for(int i=0;i<n;i++) cin>>h[i];
  sort(h.begin(),h.end());
  for(int i=0;i<=n-k;i++) d=min(d,h[i+k-1]-h[i]);
  cout<<d;
}
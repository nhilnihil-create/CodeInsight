#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,m,k=1000,ans; cin>>n>>x;
  for(int i=0; i<n; i++){
    cin>>m; x-=m;
    k=min(k,m);
  }
  cout<<n+x/k;
}
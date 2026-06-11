#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d,x,a,ans; cin>>n>>d>>x;
  ans=n;
  for(int i=0; i<n; i++){
    cin>>a; x+=d/a;
    if(d%a) x++;
  }
  cout<<x;
}
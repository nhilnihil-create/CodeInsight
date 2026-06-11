#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t,a,h,ans; cin>>n>>t>>a;
  double d=100100,tmp;
  for(int i=1; i<=n; i++){
    cin>>h;
    tmp=abs(t-h*0.006-a);
    if(d>tmp) d=tmp,ans=i;
  }
  cout<<ans;
}
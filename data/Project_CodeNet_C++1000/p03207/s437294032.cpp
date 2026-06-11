#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,p,a=0,m=0; cin>>n;
  for(int i=0; i<n; i++){
    cin>>p; a+=p; m=max(m,p);
  }
  cout<<a-m/2;
}
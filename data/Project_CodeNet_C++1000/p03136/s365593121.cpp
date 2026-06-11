#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,l,m=1,s=0; cin>>n;
  for(int i=0; i<n; i++){
    cin>>l; s+=l; m=max(m,l);
  }
  cout<<(s-m>m?"Yes":"No");
}
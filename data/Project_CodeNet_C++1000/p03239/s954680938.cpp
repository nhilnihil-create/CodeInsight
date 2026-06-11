#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t,c=1001,a; cin>>n>>t;
  for(int i=1; i<=n; i++){
    int cn,tn; cin>>cn>>tn;
    if(tn<=t) c=min(c,cn);
  }
  cout<<(c<1001?to_string(c):"TLE");
}
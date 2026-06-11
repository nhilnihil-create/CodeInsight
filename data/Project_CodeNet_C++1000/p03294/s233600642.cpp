#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,s=0; cin>>n;
  for(;n--;) cin>>a,s+=a-1;
  cout<<s;
}

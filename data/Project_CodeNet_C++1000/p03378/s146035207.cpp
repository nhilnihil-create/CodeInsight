#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,x,l=0,r=0; cin>>n>>m>>x;
  int a[m]; for(int i=0; i<m; i++) cin>>a[i];
  for(int i=0; i<m; i++){
    if(a[i]<x) l++;
    else r++;
  }
  cout<<min(l,r);
}

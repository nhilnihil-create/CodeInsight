#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,m,x,l=0,r=0; cin>>m>>m>>x;
  for(int i=0; i<m; i++){
    cin>>a;
    if(a<x) l++;
    else r++;
  }
  cout<<min(l,r);
}
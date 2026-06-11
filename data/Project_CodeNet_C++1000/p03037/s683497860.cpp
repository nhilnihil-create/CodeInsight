#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,r,l,a,maxL=0,minR=100100; cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>l>>r;
    maxL=max(l,maxL),minR=min(r,minR);
  }
  a=minR-maxL+1;
  cout<<(a<0?0:a);
}
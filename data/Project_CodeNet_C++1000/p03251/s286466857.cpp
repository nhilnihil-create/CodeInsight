#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int n,m,mx,my,x,y; cin>>n>>m>>mx>>my;
  rep(i,n) cin>>x,mx=max(mx,x);
  rep(i,m) cin>>y,my=min(my,y);
  cout<<(mx<my?"No War":"War");
}
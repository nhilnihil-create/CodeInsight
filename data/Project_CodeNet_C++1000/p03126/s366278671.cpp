#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int n,m,f,g,c=0; cin>>n>>m;
  int a[m]={0};
  rep(i,n){
    cin>>f;
    rep(i,f) cin>>g,a[--g]++;
  }
  for(int i=0; i<m; i++) if(a[i]==n) c++;
  cout<<c;
}
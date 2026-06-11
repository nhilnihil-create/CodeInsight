#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,m[110];
  cin>>n>>x;
  int g=x;
  for(int i=0;i<n;i++){
     cin>>m[i];
     g-=m[i];
  }
  sort(m,m+n);
  if(g<m[0]){ cout<<n; return 0; }
  cout<<g/m[0]+n;
}

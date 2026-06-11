#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  int mini=1e8;
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    x-=m;
    mini=min(mini,m);
  }
  cout<<n+x/mini<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int a[m+1];
  for(int i=0;i<=m;i++){
    a[i]=0;
  }
  for(int i=0;i<n;i++){
    int b;
    cin>>b;
    for(int j=0;j<b;j++){
      int c;
      cin>>c;
      a[c]++;
      //cout<<a[c]<<" ";
    }
  }
  int kotae=0;
  for(int i=1;i<=m;i++){
    if(a[i]==n)kotae++;
  }
  cout<<kotae<<endl;
  return 0;
}
    



#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int a[n][m],b[250009][4];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int k;
      cin>>k;
      a[i][j]=k;
    }
  }
  int t=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++){
      if(a[i][j]%2==1){
        b[t][0]=i+1;
        b[t][1]=j+1;
        b[t][2]=i+1;
        b[t][3]=j+2;
        a[i][j+1]++;
        t++;
      }
    }
  }
  for(int i=0;i<n-1;i++){
    if(a[i][m-1]%2==1){
      b[t][0]=i+1;
      b[t][1]=m;
      b[t][2]=i+2;
      b[t][3]=m;
      a[i+1][m-1]++;
      t++;
    }
  }
  cout<<t<<endl;
  for(int i=0;i<t;i++){
    cout<<b[i][0]<<' '<<b[i][1]<<' '<<b[i][2]<<' '<<b[i][3]<<endl;
  }
}

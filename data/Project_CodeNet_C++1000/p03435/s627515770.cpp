#include <bits/stdc++.h>
using namespace std;

int main() {
  int c[3][3];
  int a[3],b[3];
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cin>>c[i][j];
      if(i==0)b[j]=c[i][j];
    }
  }
  a[0]=0;
  a[1]=c[1][0]-b[0];
  a[2]=c[2][0]-b[0];
  bool valid=true;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(c[i][j]!=a[i]+b[j]) valid =false;
    }
  }
  if(valid) cout<<"Yes\n";
  else cout<<"No\n";
}

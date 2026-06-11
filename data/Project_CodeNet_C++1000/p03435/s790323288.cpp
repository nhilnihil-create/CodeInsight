#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int a[5],b[5],c[5][5],i,j,k;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      cin >> c[i][j];
    }
  }
  for(i=0;i<=c[0][0];i++){
    int res=0;
    a[0]=i;
    b[0]=c[0][0]-a[0],b[1]=c[0][1]-a[0],b[2]=c[0][2]-a[0];
    a[1]=c[1][0]-b[0],a[2]=c[2][0]-b[0];
  for(j=0;j<3;j++){
    for(k=0;k<3;k++){
      if(a[j]+b[k]!=c[j][k] || a[j]<0 || b[k]<0){
        res=1;
      }
    }
  }
    if(res==0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
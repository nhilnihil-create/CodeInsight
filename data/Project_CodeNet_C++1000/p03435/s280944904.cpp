#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, j, k, c[3][3], a[3], b[3];
  
  rep(i,3){
    rep(j,3){
      cin >> c[i][j];
    }
  }
  
  for(i=0;i<c[0][0]+1;i++){
    a[0]=i;
    b[0]=c[0][0]-i;
    for(j=0;j<c[1][1]+1;j++){
      a[1]=j;
      b[1]=c[1][1]-j;
      for(k=0;k<c[2][2]+1;k++){
        a[2]=k;
        b[2]=c[2][2]-k;
        if(c[0][1]==i+c[1][1]-j && c[0][2]==i+c[2][2]-k && c[1][0]==j+c[0][0]-i && c[1][2]==j+c[2][2]-k && c[2][0]==k+c[0][0]-i && c[2][1]==k+c[1][1]-j){
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  char c[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> c[i][j];
    }
  }
  int ans=0;
  char d[n][n];
  for(int i=0;i<n;i++){
    bool f=true;
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        d[j][k]=c[(j+i)%n][k];
      }
    }
    for(int j=0;j<n;j++){
      for(int k=j;k<n;k++){
        if(d[j][k]!=d[k][j]){
          f=false;
        }
      }
    }
    if(f){
      ans+=(n-i);
    }
  }
  for(int i=1;i<n;i++){
    bool f=true;
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        d[j][k]=c[j][(k+i)%n];
      }
    }
    for(int j=0;j<n;j++){
      for(int k=j;k<n;k++){
        if(d[j][k]!=d[k][j]){
          f=false;
        }
      }
    }
    if(f){
      ans+=(n-i);
    }
  }
  cout << ans << endl;
}
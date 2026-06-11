#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  bool f[40][40];
  int e,g;
  for(int i=0;i<40;i++){
    for(int j=0;j<40;j++){
      f[i][j]=0;
    }
  }
  for(int i=0;i<n;i++){
    cin >> e;
    for(int j=0;j<e;j++){
      cin >> g;
      f[i][g-1]=1;
    }
  }
  int ans=m;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(f[j][i]==0){
        ans--;
        break;
      }
    }
  }
  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<int>> C(10,vector<int>(10));
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      cin >> C[i][j];
    }
  }
  vector<int> cost(10);
  cost[1]=0;
  for(int i=0;i<=9;i++){
    if(i==1){
      continue;
    }
    cost[i]=C[i][1];
  }
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=0;i<=9;i++){
      if(i==1){
        continue;
      }
      for(int j=0;j<=9;j++){
        if(j==1){
          continue;
        }
        if(C[i][j]+cost[j]<cost[i]){
          cost[i]=C[i][j]+cost[j];
          flag=true;
        }
      }
    }
  }
  ll ans=0;
  for(int i=0;i<H*W;i++){
    int A;
    cin >> A;
    if(A==-1 || A==1){
      continue;
    }
    ans+=cost[A];
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > c(10,vector<int>(10));
int mp=1e9;

void dfs(int A,int sum){
  for(int i=0;i<10;i++){
    if(i==A){
      continue;
    }
    if(sum+c.at(A).at(i)<mp){
      if(i==1){
        mp=sum+c.at(A).at(i);
      }else{
        dfs(i,sum+c.at(A).at(i));
      }
    }
  }
}

int main(){
  int H,W;
  cin >> H >> W;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin >> c.at(i).at(j);
    }
  }
  int64_t ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int A;
      cin >> A;
      if(A==-1){
        continue;
      }
      if(A==1){
        continue;
      }
      mp=c.at(A).at(1);
      dfs(A,0);
      ans+=mp;
    }
  }
  cout << ans << endl;
  return 0;
}

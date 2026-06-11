#include <bits/stdc++.h>
using namespace std;
int INF=1e9+7;
long long DP[1005][1005];
int main(){
  int H,W;cin>>H>>W;
  DP[1][1]=1;
  for(int i=0;i<H;i++){
    string S;cin>>S;
    for(int j=0;j<W;j++){
      DP[i+1][j+1]%=INF;
      if(S.at(j)=='.'){DP[i+1][j+2]+=DP[i+1][j+1];DP[i+2][j+1]+=DP[i+1][j+1];}
    }
  }
  cout<<DP[H][W]<<endl;
}
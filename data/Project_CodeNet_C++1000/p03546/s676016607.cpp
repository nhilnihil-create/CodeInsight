#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
  int H,W; cin>>H>>W;
  
  vector<vector<int>> WF(10,vector<int>(10));
  REP(i,10) REP(j,10) cin>>WF[i][j];
  
  REP(i,10) REP(j,10) REP(k,10)
    WF[j][k]=min(WF[j][k],WF[j][i]+WF[i][k]);
  
  int a,ans=0;
  REP(i,H*W) {
    cin>>a; if(a!=-1) ans+=WF[a][1];
  }
  cout<<ans<<endl;
}
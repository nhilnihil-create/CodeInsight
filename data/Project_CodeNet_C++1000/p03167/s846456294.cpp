#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++){
    cin>>a[i];
  }
  vector<vector<int>>dp(H,vector<int>(W));
  vector<vector<bool>>seen(H,vector<bool>(W,false));
  dp[0][0]=1;
  queue<pair<int,int>>q;
  q.push(make_pair(0,0));
  while(!q.empty()){
    
    auto p=q.front();q.pop();
    int y=p.first,x=p.second;
   
    seen[y][x]=true;
    if(x+1<W&&a[y][x+1]!='#'){
      if(!seen[y][x+1]){q.push(make_pair(y,x+1));}
      dp[y][x+1]+=dp[y][x];
      dp[y][x+1]%=mod;
      seen[y][x+1]=true;
    }
    if(y+1<H&&a[y+1][x]!='#'){
      if(!seen[y+1][x]){q.push(make_pair(y+1,x));}
      dp[y+1][x]+=dp[y][x];
      dp[y+1][x]%=mod;
      seen[y+1][x]=true;
    }
  }

  cout<<dp[H-1][W-1]<<endl;
  return 0;  
}
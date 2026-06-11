#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
  int H,W;
  cin>>H>>W;
  vector<string> A(H);
  for(string &S:A)
    cin>>S;
  vector<vector<bool>> B(H,vector<bool>(W,true));
  queue<pair<pair<int,int>,int>> C;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      if(A[i][j]=='#'){
        C.push({{i,j},0});
        B[i][j]=false;
      }
  int ans=0;
  while(!C.empty()){
    pair<pair<int,int>,int> p=C.front();
    C.pop();
    ans=max(ans,p.second);
    for(int i=0;i<4;i++){
      int x=p.first.first+dx[i],y=p.first.second+dy[i];
      if(0<=x && x<H && 0<=y && y<W && B[x][y]){
        C.push({{x,y},p.second+1});
        B[x][y]=false;
      }
    }
  }
  cout<<ans<<endl;
}
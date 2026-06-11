#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> xx={0,1,0,-1},yy={1,0,-1,0};
signed main(){
  int H,W;
  cin>>H>>W;
  vector<string> A(H);
  for(string &S:A)
    cin>>S;
  int k=0;
  for(string &S:A)
    for(char &c:S)
      if(c=='.')
        k++;
  vector<vector<int>> B(H,vector<int>(W,0));
  B[0][0]=1;
  queue<pair<int,int>> C;
  C.push(make_pair(0,0));
  while(!C.empty()){
    int x=C.front().first,y=C.front().second;
    C.pop();
    if(x==H-1 && y==W-1){
      cout<<k-B[x][y]<<endl;
      return 0;
    }
    for(int i=0;i<4;i++){
      int xxx=x+xx[i],yyy=y+yy[i];
      if(0<=xxx && xxx<H && 0<=yyy && yyy<W && B[xxx][yyy]==0 && A[xxx][yyy]=='.'){
        B[xxx][yyy]=B[x][y]+1;
        C.push(make_pair(xxx,yyy));
      }
    }
  }
  cout<<-1<<endl;
}
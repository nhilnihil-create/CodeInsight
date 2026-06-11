#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

int dy[8]={0,0,1,-1,1,1,-1,-1};
int dx[8]={1,-1,0,0,1,-1,1,-1};

signed main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> A(H,vector<char>(W));
  rep(i,H){
    rep(j,W){
      cin>>A[i][j];
      if(A[i][j]!='#')A[i][j]='0';
    }
  }
  rep(i,H){
    rep(j,W){
      rep(k,8){
        int Nh=i+dy[k];
        int Nw=j+dx[k];
        if(Nh<0||Nh>=H||Nw<0||Nw>=W)continue;
        if(A[i][j]!='#'&&A[Nh][Nw]=='#')A[i][j]+=1;
      }
    }
  }
  rep(i,H){
    rep(j,W){
      cout<<A[i][j];
    }
    cout<<endl;
  }
  return 0;
}
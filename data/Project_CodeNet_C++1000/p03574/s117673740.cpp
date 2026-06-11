#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
      cin>>s[i];
  }
  vector<int>dx={0,0,-1,1,-1,-1,1,1};
  vector<int>dy={1,-1,0,0,1,-1,1,-1};
  vector<vector<char>>ans(H,vector<char>(W));
  for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
          if(s[i][j]=='#'){ans[i][j]='#';}
          else{
            int cnt=0;
            for(int k=0;k<8;k++){
              int nx=j+dx[k],ny=i+dy[k];
              if(nx<0||nx>=W||ny<0||ny>=H){continue;}
              if(s[ny][nx]=='#'){cnt++;}
            }
            ans[i][j]=(char)(cnt+'0');
          }
      }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
        cout<<ans[i][j];
    }cout<<endl;
  }
  return 0;
}

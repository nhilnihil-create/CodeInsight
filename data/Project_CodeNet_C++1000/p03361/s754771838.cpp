#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=10007;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>>s(H+2,vector<char>(W+2));
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>s[i][j];
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){ 
      if(s[i][j]=='#'){
        bool ok=true;
        if(s[i-1][j]=='#'){ok=false;}
        if(s[i+1][j]=='#'){ok=false;}
        if(s[i][j-1]=='#'){ok=false;}
        if(s[i][j+1]=='#'){ok=false;}
        if(ok){cout<<"No"<<endl;return 0;}
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;  
}
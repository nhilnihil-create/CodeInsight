#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF=1e18;
const int mod = 1000000007;

int H,W;
long long d[305][305];

void floyd(){
  for(int k=0;k<=9;k++){
    for(int i=0;i<=9;i++){
      if(d[i][k]==INF){continue;}
      for(int j=0;j<=9;j++){
        if(d[k][j]==INF){continue;}
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
}

int main(){
  cin>>H>>W;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      d[i][j]=((i==j)?0:INF);
    }
  }

  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      int c;
      cin>>c;
      d[i][j]=c;
    }
  }
  floyd();
  int sum=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int c;
      cin>>c;
      if(c>=0){sum+=d[c][1];}
    }
  }
  cout<<sum<<endl;
  return 0;                       
}
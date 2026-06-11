#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  vector<vector<int>>c(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  int d1=c[0][1]-c[0][0];
  int d2=c[0][2]-c[0][1];
  for(int i=1;i<3;i++){
    if(c[i][1]-c[i][0]!=d1||c[i][2]-c[i][1]!=d2){
      cout<<"No"<<endl;return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;  
}
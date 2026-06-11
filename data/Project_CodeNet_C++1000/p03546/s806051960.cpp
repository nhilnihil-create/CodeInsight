#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int main(){

  int h,w;
  cin >> h >> w;

  int dp[10][10];
  memset(dp,100000,sizeof(dp));

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin >> dp[i][j];
    }
  }

  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
  }


  int s=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int a;
      cin >> a;
      if(a!=-1){
        s+=dp[a][1];
      }
    }
  }

  cout << s << endl;

}
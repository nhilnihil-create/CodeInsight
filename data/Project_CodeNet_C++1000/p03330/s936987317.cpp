#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, C, d[39][39], c[509][509];
  cin >> n >> C;
  for(int i=1;i<=C;i++){
    for(int j=1;j<=C;j++){
      cin >> d[i][j];
    }
  } 
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> c[i][j];
    }
  }
  long long cost[4][39];
  memset(cost, 0, sizeof(cost));
  for(int k=1;k<=C;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cost[(i+j)%3][k]+=d[c[i][j]][k];
      }
    }
  }
  long long mn=1e16;
  for(int i=1;i<=C;i++){
    for(int j=1;j<=C;j++){
      if(i==j)continue;
      for(int k=1;k<=C;k++){
        if(k==i||k==j)continue;
        mn = min(mn, cost[0][i]+cost[1][j]+cost[2][k]);
      }
    }
  }
  cout << mn << endl;
}


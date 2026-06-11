#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  vector<int> a(3);
  vector<int> b(3);
  vector<vector<int>> c(3,vector<int>(3));

  a[0] = 0;
  
  rep(i,3) rep(j,3){
    cin >> c[i][j];
  }

  rep(i,3){
    b[i] = c[0][i] - a[0];
  }

  a[1] = c[1][0] - b[0];
  a[2] = c[2][0] - b[0];

  rep(i,3) rep(j,3){
    if(a[i]+b[j]!=c[i][j]){
      printf("No");
      return 0;
    }
  }

  printf("Yes");

  return 0;
}

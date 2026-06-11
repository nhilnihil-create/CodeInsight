#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, j, k, c[3][3], a[3], b[3];
  
  rep(i,3){
    rep(j,3){
      cin >> c[i][j];
    }
  }
  
  rep(i,3) b[i]=c[0][i];
  rep(i,3) a[i]=c[i][0]-b[0];
  
  rep(i,2){
    rep(j,2){
      if(c[i+1][j+1]!=a[i+1]+b[j+1]){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int c[3][3];
  rep(i, 3){
    rep(j, 3){
      cin >> c[i][j];
    }
  }
  int f = 0;
  vector<vector<int>> co ={
    {1, 0}, {2, 1}, {0, 2}
  };
  rep(i, 3){
    int nx0 = co[i][0];
    int nx1 = co[i][1];
    int d1 = c[0][nx1] - c[0][nx0];
    int d2 = c[1][nx1] - c[1][nx0];
    int d3 = c[2][nx1] - c[2][nx0];
    if(d1 != d2 || d2 != d3 || d3 != d1) f = 1;
  }
  rep(i, 3){
    int ny0 = co[i][0];
    int ny1 = co[i][1];
    int d1 = c[ny1][0] - c[ny0][0];
    int d2 = c[ny1][1] - c[ny0][1];
    int d3 = c[ny1][2] - c[ny0][2];
    if(d1 != d2 || d2 != d3 || d3 != d1) f = 1;
  }
  if(f == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}

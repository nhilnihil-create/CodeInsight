#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  vector<vector<int>> grid(3,vector<int>(3));
  for (auto && a : grid) {
    for(auto &&b : a){
      cin>>b;
    }
  }
  bool flg = false;
  int a[3];
  int b[3];
  for (a[0] = 0; a[0] < 101; a[0]++) 
  for (a[1] = 0; a[1] < 101; a[1]++) 
  for (a[2] = 0; a[2] < 101; a[2]++) 
  {
    b[0] = grid[0][0] - a[0];
    b[1] = grid[1][1] - a[1];
    b[2] = grid[2][2] - a[2];

    if (a[0]+b[1] == grid[0][1] &&
        a[0]+b[2] == grid[0][2] &&
        a[1]+b[0] == grid[1][0] &&
        a[1]+b[2] == grid[1][2] &&
        a[2]+b[1] == grid[2][1] &&
        a[2]+b[0] == grid[2][0]  )
    flg = true;
  }
    cout << (flg ? "Yes" : "No") << endl;
}
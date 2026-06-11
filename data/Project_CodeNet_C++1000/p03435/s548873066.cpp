#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  vector<vector<int> > c = { 
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
  rep(i, 3){
    rep(j, 3){
      cin >> c[i][j];
    }
  }

  bool ans = false;
  int a1, a2, a3, b1, b2, b3;
  rep(i, 101){
    a1 = i;
    b1 = c[0][0] - a1;
    b2 = c[0][1] - a1;
    b3 = c[0][2] - a1;
    a2 = c[1][0] - b1;
    a3 = c[2][0] - b1;

    if ((c[1][1] == a2 + b2) &&
        (c[1][2] == a2 + b3) &&
        (c[2][1] == a3 + b2) &&
        (c[2][2] == a3 + b3)){
      ans = true;
          break;
    }
  }
  if (ans == true){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
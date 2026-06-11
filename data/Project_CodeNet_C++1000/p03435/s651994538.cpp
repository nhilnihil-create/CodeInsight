#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> c(3, vector<int>(3));

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      cin >> c[i][j];
    }
  }

  vector<int> a(3);
  vector<int> b(3);
  bool judge = false;
  for(int i = 0; i <= 100; ++i) {
    a[0] = i;
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][1] + b[1];
    a[2] = c[2][1] + b[1];

    for(int j = 0; j < 3; ++j) {
      for(int k = 0; k < 3; ++k) {
        if(c[j][k] == (a[j] + b[k])) {
          judge = true;
        }
        else {
          judge = false;
          break;
        }
      }
      if(!judge) {
        break;
      }
    }
    if(judge) {
      break;
    }
  }

  cout << (judge ? "Yes" : "No") << endl;
  return 0;
}

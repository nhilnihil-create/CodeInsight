#include<iostream>
using namespace std;
#include<vector>

int main() {
  int n, m, res = 0;
  cin >> n >> m;
  int lb[m][n], p[m], k[m];
  for(int i = 0; i < m; i++) {
    cin >> k[i];
    for(int j = 1; j <= k[i]; j++) {
      cin >> lb[i][j];
    }
  }
  for(int i = 0; i < m; i++) {
    cin >> p[i];
  }
  bool flag;
  int sw = 0 , temp;
  for(int bit = 0; bit < (1<<n); bit++) {
    flag = true;
    vector<int> S;
    for(int i = 0; i < n; i++) {
      if(bit & (1<<i)) {
        S.push_back(i);
      }
    }
    for(int i = 0; i < m; i++) {
      sw = 0;
      for(int j = 1; j <= k[i]; j++) {
        if(bit & (1<<(lb[i][j]-1))) sw++;
      }
      if(sw%2 != p[i]) {
        flag = false;
        break;
      }
    }

    if(flag) res++;
   }
   cout << res << endl;
}
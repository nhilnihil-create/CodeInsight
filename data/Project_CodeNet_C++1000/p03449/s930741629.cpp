#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  int a[2][N];
  FOR(i,0,2) {
    FOR(j,0,N) {
      cin >> a[i][j];
    }
  }
  FOR(i,0,2) {
    FOR(j,0,N) {
      if(i==0 && j==0) continue;
      else if(i==0 && j>0) {
        a[i][j] = a[i][j-1] + a[i][j];
      }
      else if(i==1 && j==0) {
        a[i][j] = a[i][j] + a[0][0];
      }
      else {
        a[i][j] = max(a[i-1][j], a[i][j-1]) + a[i][j];
      }
    }
  }
  cout << a[1][N-1] << endl;
  return 0;
  
}



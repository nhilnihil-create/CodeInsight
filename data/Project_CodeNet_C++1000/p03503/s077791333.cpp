#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;
int MIN_INT = -1e9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(5*2)), P(N, vector<int>(11));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }
  int res = MIN_INT;

  for(int open = 1; open < (1 << 10); open++) {
    int cc = 0;
    for(int i = 0; i < N; i++) {
      int c = 0;
      for(int j = 0; j < 10; j++) {
        if((open >> j & 1) && F[i][j]) {
          c++;
        }
      }
      cc += P[i][c];
    }
    if(res < cc) {
      res = cc;
    }
  }

  cout << res << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int A, B;
vector<string> grid(100, string(100, '#'));
int main(){
  cin >> A >> B;
  A--, B--;
  REP(i, 50){
    REP(j, 100){
      grid[i][j] = '.';
    }
  }

  REP(i, A){
    int y = 51 +2 * (i / 50), x = i % 50 * 2;
    grid[y][x] = '.';
  }
  REP(i, B){
    int y = 2*(i / 50), x = i % 50 * 2;
    grid[y][x] ='#';
  }
  cout << 100 << " " << 100 << endl;
  REP(i, 100){
    cout << grid[i] << endl;
  }
  return 0;
}

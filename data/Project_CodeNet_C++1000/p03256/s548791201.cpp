#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

vector<int> E[MAX];
string S;

enum Color { WHITE, GRAY, BLACK };

Color color[MAX][2];

void dfs(int x, int i) {
  if (color[x][i] == GRAY) {
    cout << "Yes\n";
    exit(0);
  }
  if (color[x][i] == BLACK) {
    return;
  }

  color[x][i] = GRAY;
  for (int y : E[x]) {
    if (i == 1) {
      if (S[x] != S[y]) dfs(y, 0);
    } else {
      if (S[x] == S[y]) dfs(y, 1);
    }
  }
  color[x][i] = BLACK;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  cin >> S;

  REP(i, M) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  REP(i, N) REP(j, 2) {
    if (color[i][j] == WHITE) {
      dfs(i, j);
    }
  }

  cout << "No\n";
  return 0;
}

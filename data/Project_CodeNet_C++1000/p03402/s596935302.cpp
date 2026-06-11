#include <iostream>
using namespace std;

#define out(v) cout<<v<<"\n"
#define rep(i,n) for(int i=0;i<(n);++i)

const int WHITE = 0, BLACK = 1;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int A, B; cin >> A >> B;

  int board[100][100];
  rep(i, 100) rep(j, 100) {
    if (i < 50)
      board[i][j] = WHITE;
    else
      board[i][j] = BLACK;
  }
  rep(i, A-1) {
    board[99-(i / 50)*2][2*(i % 50)] = WHITE;
  }
  rep(i, B-1) {
    board[(i / 50)*2][2*(i % 50)] = BLACK;
  }
  cout << "100 100\n";
  rep(i, 100) {
    rep(j, 100) {
      cout << (board[i][j] == WHITE ? '.' : '#');
    }
    cout << "\n";
  }

  return 0;
}

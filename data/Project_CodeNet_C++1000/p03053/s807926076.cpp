#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;

const int MAXH = 1010;
const int MAXW = 1010;

int h, w;

string s[MAXH];
bool visited[MAXW][MAXH];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
  return 0 <= x && x < w && 0 <= y && y < h;
}

void solve() {
  vector<P> cur;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      if (s[i][j] == '#') {
        cur.push_back(P(i, j));
        visited[i][j] = true;
      }
    }
  }

  vector<P> next;
  int cnt = 0;
  while (cur.size() > 0) {
    for (int i=0;i<cur.size();i++) {
      P p = cur[i];
      for (int j=0;j<4;j++) {
        int nx = p.second + dx[j], ny = p.first + dy[j];
        if (!visited[ny][nx] && check(nx, ny)) {
          visited[ny][nx] = true;
          next.push_back(P(ny, nx));
        }
      }
    }
    cnt++;
    swap(cur, next);
    next.clear();
  }

  cout << (cnt - 1) << endl;
}

int main() {
  cin >> h >> w;
  for (int i=0;i<h;i++) {
    cin >> s[i];
  }
  solve();
}

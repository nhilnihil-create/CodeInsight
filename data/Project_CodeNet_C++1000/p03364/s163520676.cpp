#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 305;

char grid [MAX_N][MAX_N];
int forb [MAX_N];

int n;
void process (int i, int j, int k, int l) {
  if (grid[i][j] == grid[k][l]) return;
  forb[(j + n - k) % n] = 1;
}

vector<pair<int, int>> bucket [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bucket[(i + j) % n].push_back({i, j});
    }
  }

  for (int i = 0; i < n; i++) {
    for (auto p : bucket[i]) {
      for (auto q : bucket[i]) {
        process(p.first, p.second, q.first, q.second);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!forb[i]) {
      ans += n;
    }
  }

  cout << ans << endl;
}

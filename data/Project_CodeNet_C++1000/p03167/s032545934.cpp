#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

constexpr size_t MAXN = 1e5;
constexpr size_t MAXM = 1e5;
constexpr int MOD = 1e9 + 7;

void solve() {
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int>> grid;
  grid.reserve(H);
  for (int y = 0; y < H; ++y) {
    grid.push_back(std::vector<int>());
    grid.back().reserve(W);
    for (int x = 0; x < W; ++x) {
      char a;
      std::cin >> a;
      grid[y].push_back(a == '.' ? 0 : -1);
    }
  }

  grid[0][0] = 1;

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (grid[y][x] == -1 || y + x == 0) continue;
      if (y == 0) {
        grid[y][x] = grid[y][x - 1];
        continue;
      }
      if (x == 0) {
        grid[y][x] = grid[y - 1][x];
        continue;
      }
      int top = grid[y - 1][x] == -1 ? 0 : grid[y - 1][x];
      int left = grid[y][x - 1] == -1 ? 0 : grid[y][x - 1];
      grid[y][x] = (top + left) % MOD;
    }
  }

  std::cout << grid.back().back() << "\n";
}

void warp() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
}

int main() {
  warp();
  solve();
  return 0;
}

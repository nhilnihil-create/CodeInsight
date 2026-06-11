#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<long long>> warshall_floyd(std::vector<std::vector<long long>> dist) {
  const long long LINF = 1000000000000000018LL;
  int n = (int)dist.size();
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][k] == LINF) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (dist[k][j] == LINF) {
          continue;
        }
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::vector<long long>> G(10, std::vector<long long>(10));
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      std::cin >> G[y][x];
    }
  }
  auto dist = warshall_floyd(G);

  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int A;
      std::cin >> A;
      if (A != -1) {
        ans += dist[A][1];
      }
    }
  }
  std::cout << ans << "\n";

  return 0;
}
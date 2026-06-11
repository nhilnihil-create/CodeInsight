#include <iostream>
#include <string>
#include <algorithm>

int main() {
  int H, W;
  std::cin >> H >> W;
  std::string s[50], ss[50];
  for (int i = 0; i < H; ++i) {
    std::cin >> s[i];
    ss[i] = s[i];
  }

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (s[y][x] == '#') {
        continue;
      }
      const int minY = std::max(y - 1, 0);
      const int maxY = std::min(y + 1, H - 1);
      const int minX = std::max(x - 1, 0);
      const int maxX = std::min(x + 1, W - 1);
      int bombs = 0;
      for (int yy = minY; yy <= maxY; ++yy) {
        for (int xx = minX; xx <= maxX; ++xx) {
          if (s[yy][xx] == '#') {
            ++bombs;
          }
        }
      }
      ss[y][x] = '0' + bombs;
    }
  }
  for (int i = 0; i < H; ++i) {
    std::cout << ss[i] << std::endl;
  }
}
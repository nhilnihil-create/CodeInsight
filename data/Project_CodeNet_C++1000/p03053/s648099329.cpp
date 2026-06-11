#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<typename T>
std::vector<std::vector<T>> mk2d(size_t s1, size_t s2, T const& val) {
  std::vector<T> tmp(s2, val);
  return std::vector<std::vector<T>>(s1, tmp);
}
int const dx[4] = {0, 1, 0, -1};
int const dy[4] = {1, 0, -1, 0};
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int H, W; std::cin >> H >> W;
  auto bm = mk2d(H+2, W+2, '#');
  std::queue<std::tuple<int,int,int>> q;
  for(int h = 1; h <= H; ++h) {
    for(int w = 1; w <= W; ++w) {
      std::cin >> bm[h][w];
      if(bm[h][w]=='#') q.emplace(w, h, 0);
    }
  }
  auto dist = mk2d(H+2, W+2, H*W+1);
  while(!q.empty()) {
    int x, y, c;
    std::tie(x, y, c) = q.front(); q.pop();
    if(dist[y][x] <= c) continue;
    dist[y][x] = c;
    for(int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(bm[ny][nx] == '.') q.emplace(nx, ny, c+1);
    }
  }
  int ans = 0;
  for(int h = 1; h <= H; ++h) {
    for(int w = 1; w <= W; ++w) ans = std::max(ans, dist[h][w]);
  }
  fin(ans);
  return 0;
}

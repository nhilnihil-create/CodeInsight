#include <iostream>
#include <vector>
#include <set>

using ll = long long;

int const nmax = 200000;
std::set<int> line[1 + nmax];

int block(int x, int y) {
  return line[y].find(x) != line[y].end();
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  for(int i = 1;i <= m; i++)
    line[i].insert(n + 1);
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    line[y].insert(x);
  }
  int x = 1, y = 1;
  int result = n, step = 0;

  while(true) {
    result = std::min(result, step + *line[y].lower_bound(x) - x);
    if(1 == block(x + 1, y))
      break;
    else {
      x++;
      if(y < m && block(x, y + 1) == 0)
        y++;
    }
    step++;
  }
  std::cout << result;
}

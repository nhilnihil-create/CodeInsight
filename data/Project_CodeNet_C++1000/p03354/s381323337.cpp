#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

template <typename Container, class T>
bool contains(const Container& c, T v)
{
  return std::find(c.begin(), c.end(), v) != c.end();
}

template <typename Map ,class T>
bool contains_map(const Map &c, const T &v)
{
  return c.find(v) != c.end();
}

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<int> input(N);
  std::vector<int> group_per_num(N); // index of group_val
  std::vector<int> group_val;
  group_val.push_back(-1);
  int g_next = 0;

  for(int i=0; i<N; i++) {
    int p;
    std::cin >> p;
    input[i] = --p; // 0-origin
  }

  std::multimap<int, int> xy;
  for(int i=0; i<M; i++) {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    if(y < x) {
      std::swap(x, y);
    }
    xy.insert(std::make_pair(x, y));
  }

  // read input and assign group
  std::map<int, int> lut;
  for(auto z: xy) {
    int x = z.first, y = z.second;

    int &gpn_x = group_per_num[x];
    int &gpn_y = group_per_num[y];
    int &gx = group_val[group_per_num[x]];
    int &gy = group_val[group_per_num[y]];

    if(gx < 0 && gy < 0) {
      group_val.push_back(g_next);
      gpn_x = gpn_y = group_val.size() - 1;
      g_next++;
    } else if(gx >= 0 && gy >= 0 && gx != gy) {
      int new_g = std::min(gx, gy);
      int old_g = std::max(gx, gy);
      for(auto &gv: group_val) {
        if(gv == old_g) {
          gv = new_g;
        }
      }

    } else if(gx < 0) {
      gpn_x = gpn_y;
    } else {
      gpn_y = gpn_x;
    }
  }
  // print_container(group_per_num, "group_per_num");

  std::map<int, std::vector<int>> groups;
  int ret = 0;
  for(int i=0; i<N; i++) {
    auto gpn = group_per_num[i];
    auto g = group_val[gpn];
    if(g < 0) {
      if(i == input[i]) {
        ret++;
      }
    } else {
      groups[g].push_back(i);
    }
  }

  // count numbers such that p == i after permutation
  for(auto g: groups) {
    // std::cout << "g.first: " << g.first << std::endl;
    // print_container(g.second, "g.second");
    for(auto i: g.second) {
      // std::cout << "i: " << i << " input[i]" << input[i] << std::endl;
      if(contains(g.second, input[i])) {
        ret++;
      }
    }
  }

  std::cout << ret << std::endl;
  return 0;
}


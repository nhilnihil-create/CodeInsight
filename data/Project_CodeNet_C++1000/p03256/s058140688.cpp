#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

struct Vertex {
  std::vector<int> next;
  int type;
};

class Solver {
 public:
  Solver(std::vector<Vertex> vertices) : vertices(std::move(vertices)) {
  }
  bool has_cycle() {
    was.resize(vertices.size() * bad_string.size());
    for (int i = 1; i < (int)vertices.size(); i++) {
      if (dfs(i, 0)) {
        return true;
      }
    }
    return false;
  }

 private:
  std::vector<Vertex> vertices;
  std::string bad_string = "AABB";
  std::vector<int> was;
  bool dfs(int v, int s_pos) {
    //printf("%d %d\n", v, s_pos);
    s_pos %= bad_string.size();
    if (vertices[v].type != bad_string[s_pos]) {
      return false;
    }
    int v_id = v * (int)bad_string.size() + s_pos;
    if (was[v_id] == 1) {
      return true;
    }
    if (was[v_id] == 2) {
      return false;
    }
    was[v_id] = 1;
    for (auto next_v : vertices[v].next) {
      if (dfs(next_v, s_pos + 1)) {
        return true;
      }
    }
    was[v_id] = 2;
    return false;
  }
};

int main(void) {
  int n, m;

  while (scanf("%d%d", &n, &m) == 2) {
    std::string s;
    std::cin >> s;
    std::vector<Vertex> vertices(n + 1);
    for (int i = 0; i < n; i++) {
      vertices[i + 1].type = s[i];
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      vertices[a].next.push_back(b);
      vertices[b].next.push_back(a);
    }

    if (Solver(std::move(vertices)).has_cycle()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}

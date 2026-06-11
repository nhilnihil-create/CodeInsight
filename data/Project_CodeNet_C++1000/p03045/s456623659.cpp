#include <iostream>
#include <set>
#include <vector>

using namespace std;

int get_parent_idx(vector<int> &vec, int x) {
  if (x == vec[x])
    return x;
  return vec[x] = get_parent_idx(vec, vec[x]);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; ++i)
    vec[i] = i;

  int x, y, z;
  while (cin >> x >> y >> z) {
    int px = get_parent_idx(vec, x);
    int py = get_parent_idx(vec, y);
    if (px < py) {
      do {
        int tmp = x;
        x = vec[x];
        vec[tmp] = py;
      } while (x != px);
      vec[x] = py;
    }
    else {
      do {
        int tmp = y;
        y = vec[y];
        vec[tmp] = px;
      } while(y != px);
      vec[y] = px;
    }
  }

  for (int i = 1; i <= n; ++i)
    get_parent_idx(vec, i);

  set<int> s;
  for (int i = 1; i <= n; ++i)
    s.insert(vec[i]);

  cout << static_cast<int>(s.size()) << endl;
}
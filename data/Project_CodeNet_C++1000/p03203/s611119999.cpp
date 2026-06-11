#include <bits/stdc++.h>
template<typename T1, typename T2>
inline bool cmn (T1& a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
inline bool cmx (T1& a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<int> obj(h, w);
  for (int i = 0; i < n; i++) {
    int x, y; std::cin >> x >> y;
    x--; y--;
    cmn(obj.at(x), y);
  }
  int ret = h, right = 1;
  for (int i = 1; i < h; i++) {
    if (obj.at(i) < right) {
      ret = i;
      break;
    }
    if (right < obj.at(i)) {
      right++;
    }
  }
  std::cout << ret << std::endl;
  return 0;
}
#include <iostream>
#include <vector>

int calc(std::vector<int> a, const int count, const int i) {
  if (i >= (int)a.size()) {
    for (auto &v : a) {
      if (v % 2 == 0) {
        return count + 1;
      }
    }
    return count;
  }
  int c = count;
  --a.at(i);
  c += calc(a, count, i + 1);
  ++a.at(i);
  c += calc(a, count, i + 1);
  ++a.at(i);
  c += calc(a, count, i + 1);
  return c;
}

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a.at(i);
  std::cout << calc(a, 0, 0) << std::endl;
}

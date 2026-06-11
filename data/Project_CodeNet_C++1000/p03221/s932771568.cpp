#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  uint32_t N = 0, M = 0;
  std::cin >> N >> M;
  std::vector<std::vector<uint32_t>> data(N + 1);
  std::vector<std::pair<uint32_t, uint32_t>> PY(M);
  for (size_t m = 0; m < M; m++) {
    std::cin >> PY[m].first >> PY[m].second;
    data[PY[m].first].push_back(PY[m].second);
  }

  for (size_t n = 0; n < data.size(); n++) {
    std::sort(data[n].begin(), data[n].end());
  }

  for (size_t i = 0; i < M; i++) {
    uint32_t id = std::lower_bound(data[PY[i].first].begin(),
                                   data[PY[i].first].end(), PY[i].second) -
                  data[PY[i].first].begin();
    std::cout << std::setw(6) << std::setfill('0') << PY[i].first
              << std::setw(6) << std::setfill('0') << id + 1 << std::endl;
  }

  return 0;
}
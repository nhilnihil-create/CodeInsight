/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct City {
  int64_t index{-1};
  int64_t prefecture{-1};
  int64_t year{-1};
  string id;
};

bool Compare(const City &c1, const City &c2) {
  if (c1.prefecture == c2.prefecture) {
    return c1.year < c2.year;
  } else {
    return c1.prefecture < c2.prefecture;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  vector<City> cities(M);
  for (int64_t i = 0; i < M; ++i) {
    int64_t p, y;
    cin >> p >> y;
    cities[i].index = i;
    cities[i].prefecture = p;
    cities[i].year = y;
  }
  int64_t x = 1;
  int64_t current_prefecture = -1;
  sort(cities.begin(), cities.end(), Compare);
  char buff[13];
  vector<int64_t> map_from_original_to_sorted(M);
  for (int32_t i = 0; i < M; ++i) {
    if (cities[i].prefecture != current_prefecture) {
      current_prefecture = cities[i].prefecture;
      x = 1;
    } else {
      ++x;
    }
    snprintf(buff, sizeof(buff), "%06ld%06ld", cities[i].prefecture, x);
    cities[i].id = string(buff);
    map_from_original_to_sorted[cities[i].index] = i;
  }

  for (int32_t i = 0; i < M; ++i) {
    cout << cities[map_from_original_to_sorted[i]].id << endl;
  }

  return 0;
}

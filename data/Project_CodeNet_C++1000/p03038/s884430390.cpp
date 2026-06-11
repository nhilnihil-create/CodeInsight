#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main() {
  int64_t N, M;
  cin >> N >> M;
  map<int64_t, int64_t> card_map;
  for (int64_t n = 0; n < N; ++n) {
    int64_t A;
    cin >> A;
    ++card_map[A];
  }

  for (int64_t m = 0; m < M; ++m) {
    int64_t B, C;
    cin >> B >> C;
    card_map[C] += B;
  }
  vector<pair<int64_t, int64_t>> cards(card_map.begin(), card_map.end());
  sort(cards.begin(), cards.end(),
       [] (const auto& lhs, const auto& rhs) {
         return lhs.first > rhs.first;
       });
  int64_t cnt = 0;
  int64_t sum = 0;
  size_t idx = 0;
  while (cnt < N) {
    int64_t num = min(N-cnt, cards[idx].second);
    sum += cards[idx++].first * num;
    cnt += num;
  }
  cout << sum << endl;
  
  return 0;
}

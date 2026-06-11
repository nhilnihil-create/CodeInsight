#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<pair<int64_t, int>> DT(N);
  rep(i, N) { cin >> DT[i].second >> DT[i].first; }
  sort(DT.begin(), DT.end(), [](const auto& lhs, const auto& rhs) {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    else
      return lhs.first > rhs.first;
  });

  int64_t tmp_ans0 = 0;
  unordered_map<int, int> hist;
  for (int i = K - 1; i >= 0; --i) {
    tmp_ans0 += DT[i].first;
    hist[DT[i].second]++;
  }
  int64_t neta = hist.size();
  tmp_ans0 += neta * neta;

  vector<int64_t> sub_taste;
  for (int i = K - 1; i >= 0; --i) {
    if (hist[DT[i].second] >= 2) {
      sub_taste.emplace_back(DT[i].first);
    }
    hist[DT[i].second]--;
  }

  vector<int64_t> add_taste;
  for (int i = K; i < N; ++i) {
    if (hist.count(DT[i].second)) continue;
    add_taste.emplace_back(DT[i].first);
    hist[DT[i].second]++;
  }

  int64_t answer = tmp_ans0;
  int loop = min(sub_taste.size(), add_taste.size());
  rep(i, loop) {
    // add
    int j = i + neta;
    int64_t add = (int64_t)((j + 1) * (j + 1)) - (int64_t)(j * j);
    // sub
    int64_t sub = sub_taste[i] - add_taste[i];
    tmp_ans0 += add - sub;
    answer = max(answer, tmp_ans0);
  }
  cout << answer << endl;
  return 0;
}

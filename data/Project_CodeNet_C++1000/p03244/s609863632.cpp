/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  vector<int32_t> V(N);
  for (int32_t i = 0; i < N; ++i) {
    cin >> V[i];
  }

  vector<int32_t> guu(100000 + 1, 0);
  vector<int32_t> ki(100000 + 1, 0);
  for (int32_t i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      ++guu[V[i]];
    } else {
      ++ki[V[i]];
    }
  }

  vector<pair<int32_t, int32_t>> guu_list, ki_list;
  for (int32_t i = 1; i <= 100000; ++i) {
    if (guu[i] > 0) {
      guu_list.push_back(pair<int32_t, int32_t>(guu[i], i));
    }
    if (ki[i] > 0) {
      ki_list.push_back(pair<int32_t, int32_t>(ki[i], i));
    }
  }
  sort(guu_list.begin(), guu_list.end());
  reverse(guu_list.begin(), guu_list.end());
  sort(ki_list.begin(), ki_list.end());
  reverse(ki_list.begin(), ki_list.end());
  if (guu_list[0].second != ki_list[0].second) {
    cout << (N - guu_list[0].first - ki_list[0].first) << endl;
  } else {
    if (guu_list.size() == 1 && ki_list.size() == 1) {
      cout << N / 2 << endl;
    } else if (guu_list.size() == 1) {
      cout << (N - guu_list[0].first - ki_list[1].first) << endl;
    } else if (ki_list.size() == 1) {
      cout << (N - guu_list[1].first - ki_list[0].first) << endl;
    } else {
      if (guu_list[1].first < ki_list[1].first) {
        cout << (N - guu_list[0].first - ki_list[1].first) << endl;
      } else {
        cout << (N - guu_list[1].first - ki_list[0].first) << endl;
      }
    }
  }

  return 0;
}

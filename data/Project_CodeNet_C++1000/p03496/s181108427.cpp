#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<int> A(N);
  bool all_plus = true;
  bool all_minus = true;
  int minA = 1e6 + 1;
  int minApos;
  int maxA = -1e6 - 1;
  int maxApos;
  rep(i, N) {
    cin >> A[i];
    if (A[i] < minA) {
      minA = A[i];
      minApos = i;
    }
    if (maxA < A[i]) {
      maxA = A[i];
      maxApos = i;
    }
    if (A[i] < 0) all_plus = false;
    if (0 < A[i]) all_minus = false;
  }

  vector<pair<int, int>> answer;
  if (!all_plus && !all_minus) {
    if (abs(minA) < abs(maxA)) {
      rep(i, N) {
        A[i] += maxA;
        if (i != maxApos) answer.emplace_back(maxApos + 1, i + 1);
      }
      answer.emplace_back(maxApos + 1, maxApos + 1);
      all_plus = true;
    } else {
      rep(i, N) {
        A[i] += minA;
        if (i != minApos) answer.emplace_back(minApos + 1, i + 1);
      }
      answer.emplace_back(minApos + 1, minApos + 1);
      all_minus = true;
    }
  }

  if (all_plus) {
    for (int i = 0; i < N - 1; ++i) {
      answer.emplace_back(i + 1, i + 2);
    }
  } else if (all_minus) {
    for (int i = N; i > 1; --i) {
      answer.emplace_back(i, i - 1);
    }
  }

  cout << answer.size() << endl;
  for (auto a : answer) {
    cout << a.first << " " << a.second << endl;
  }
  return 0;
}
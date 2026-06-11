#include <bits/stdc++.h>

using namespace std;

int calc(int A, const vector<int> &a) {
  return abs(A - accumulate(a.begin(), a.end(), 0)) + (a.size() - 1) * 10;
}

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];

  int answer = numeric_limits<int>::max();
  for (int i = 0; i < pow(4, N); i++) {
    vector<int> a, b, c;
    for (int j = 0; j < N; j++) {
      int k = (i >> (2 * j)) & 3;
      if (k == 0) {
        a.push_back(L[j]);
      } else if (k == 1) {
        b.push_back(L[j]);
      } else if (k == 2) {
        c.push_back(L[j]);
      }
    }

    if (a.empty() || b.empty() || c.empty()) {
      continue;
    }

    int mp = calc(A, a) + calc(B, b) + calc(C, c);
    answer = min(answer, mp);
  }
  cout << answer << endl;

  return 0;
}

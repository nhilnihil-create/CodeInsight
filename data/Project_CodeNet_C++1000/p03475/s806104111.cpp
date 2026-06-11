#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, C, S, F;
  cin >> N;
  vector<int> t(N);
  for (int i = 0; i != N - 1; ++i) {
    cin >> C >> S >> F;
    t[i] = S + C;
    for (int j = 0; j != i; ++j) {
      if (t[j] < S) {
        t[j] = S + C;
      } else {
        t[j] += C + F - (t[j] - 1) % F - 1;
      }
    }
  }

  for (auto x: t) cout << x << endl;
}

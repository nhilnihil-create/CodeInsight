#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, M, x;
  cin >> N;
  map<int, int> D, T;
  for (int i = 0; i < N; i++) {
    cin >> x;
    ++D[x];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> x;
    ++T[x];
  }

  bool cond = true;
  for (const auto &p : T) {
    if (D[p.first] < p.second) {
      cond = false;
      break;
    }
  }
  cout << (cond ? "YES" : "NO") << endl;
  return 0;
}

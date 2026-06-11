#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  unordered_map<int, int> problems;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int D;
    cin >> D;
    ++problems[D];
  }

  bool OK = true;
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int T;
    cin >> T;
    if (problems[T] == 0) OK = false;
    --problems[T];
  }
  cout << (OK ? "YES" : "NO") << endl;
  return 0;
}

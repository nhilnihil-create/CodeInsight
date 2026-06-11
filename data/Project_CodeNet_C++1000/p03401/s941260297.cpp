#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> as(N + 2, 0);
  vector<int> vs(N + 2, 0);
  for(int i = 1; i <= N; ++i) {
    cin >> as[i];
  }
  for(int i = 1; i <= N + 1; ++i) {
    vs[i] = vs[i - 1] + abs(as[i] - as[i - 1]);
  }
  vector<int> rs(N + 1, 0);
  for(int i = 1; i <= N; ++i) {
    rs[i] = vs[i - 1] + (vs[N + 1] - vs[i + 1]) + abs(as[i + 1] - as[i - 1]);
  }
  for(int i = 1; i <= N; ++i) {
    cout << rs[i] << endl;
  }

  return 0;
}
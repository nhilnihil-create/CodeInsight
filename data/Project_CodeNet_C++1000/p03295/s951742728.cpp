#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> conflict(M);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    conflict[i] = {b, a};
  }
  sort(conflict.begin(), conflict.end());

  int answer = 1;
  int current = conflict[0].first - 1;
  for(int i = 1; i < M; ++i) {
    if(current < conflict[i].second) {
      ++answer;
      current = conflict[i].first - 1;
    }
  }
  cout << answer << endl;
  return 0;
}
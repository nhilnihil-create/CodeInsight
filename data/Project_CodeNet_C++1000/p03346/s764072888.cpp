#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) cin >> P[i];

  vector<int> Q(N);
  rep(i, N) Q[P[i] - 1] = i;

  int longest = 1;
  int current = 1;
  rep(i, N - 1) {
    if (Q[i] < Q[i + 1]) {
      ++current;
    } else {
      longest = max(longest, current);
      current = 1;
    }
  }
  longest = max(longest, current);
  int answer = N - longest;
  cout << answer << endl;
  return 0;
}
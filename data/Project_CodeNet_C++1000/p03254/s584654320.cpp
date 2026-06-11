#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  sort(a.begin(), a.end());

  int answer = 0;
  while (answer < N && a[answer] <= x) {
    x -= a[answer];
    ++answer;
  }
  if (0 < x && answer == N) --answer;
  cout << answer << endl;
  return 0;
}
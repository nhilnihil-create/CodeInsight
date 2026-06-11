#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(A.rbegin(), A.rend());

  unordered_map<int, int> count;
  int answer = 0;
  rep(i, N) {
    bool use = false;
    rep(j, 30) {
      int k = (1 << (j + 1)) - A[i];
      if (count.count(k) && count[k] > 0) {
        ++answer;
        count[k]--;
        use = true;
        break;
      }
    }
    if (!use) count[A[i]]++;
  }
  cout << answer << endl;
  return 0;
}
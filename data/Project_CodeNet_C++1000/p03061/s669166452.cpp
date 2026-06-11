#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<int> A;

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  vector<int> l(N), r(N);
  l[0] = A[0];
  r[N - 1] = A[N - 1];
  for (int i = 1; i < N; i++) {
    l[i] = gcd(l[i - 1], A[i]);
    r[N - i - 1] = gcd(r[N - i], A[N - i - 1]);
  }

  int res = max(l[N - 2], r[1]);
  for (int i = 1; i < N - 1; i++) {
    int tmp = gcd(l[i - 1], r[i + 1]);
    if (tmp > res)
      res = tmp;
  }
  cout << res << endl;

  return 0;
}

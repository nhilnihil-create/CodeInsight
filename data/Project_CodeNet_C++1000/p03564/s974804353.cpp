#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, K;

int main() {
  cin >> N >> K;
  int n = 1;
  for (int i = 0; i < N; i++)
    n = min(2 * n, n + K);

  cout << n << endl;

  return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M;

int main() {
  cin >> N >> M;

  long long int res = 1800 * M + 100 * N;
  for (int i = 0; i < M; i++)
    res *= 2;
  cout << res << endl;

  return 0;
}

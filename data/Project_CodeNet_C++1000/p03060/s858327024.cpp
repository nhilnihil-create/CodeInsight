#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<int> V, C;

int main() {
  cin >> N;
  V.resize(N);
  C.resize(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  for (int i = 0; i < N; i++)
    cin >> C[i];

  int res = 0;
  for (int i = 0; i < N; i++)
    if (V[i] - C[i] > 0)
      res += V[i] - C[i];
  cout << res << endl;

  return 0;
}

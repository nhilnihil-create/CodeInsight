#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, Z, W;
int a[2000];

int main() {
  cin >> N >> Z >> W;
  for (int i = 0; i < N; i++)
    cin >> a[i];

  if (N == 1) {
    cout << abs(a[N - 1] - W) << endl;
  } else {
    cout << max(abs(a[N - 1] - W), abs(a[N - 1] - a[N - 2])) << endl;
  }

  return 0;
}

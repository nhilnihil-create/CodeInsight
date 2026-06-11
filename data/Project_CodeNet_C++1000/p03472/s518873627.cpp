#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, H;
int a[100000], b[100000];

int main() {
  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  int a_max = 1;
  for (int i = 0; i < N; i++)
    if (a_max < a[i])
      a_max = a[i];
  sort(b, b + N, greater<int>());

  int b_idx = 0;
  int count = 0;
  while (H > 0) {
    if (b_idx < N && b[b_idx] > a_max)
      H -= b[b_idx++];
    else
      H -= a_max;
    count++;
  }
  cout << count << endl;

  return 0;
}

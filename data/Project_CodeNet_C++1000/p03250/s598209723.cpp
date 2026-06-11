#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int A[3];

int main() {
  cin >> A[0] >> A[1] >> A[2];

  sort(A, A + 3);

  cout << A[0] + A[1] + 10 * A[2] << endl;

  return 0;
}

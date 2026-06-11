#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main() {
  int N; cin >> N;

  vector<long long> A(N);
  for (int i = 1; i <= N; i++) {
    cin >> A[i-1];
    A[i-1] -= i;
  }

  sort(A.begin(), A.end());

  long long ans = 0;
  for (long long a : A) {
    ans += abs(a - A[N/2]);
  }

  cout << ans << endl;

  return 0;
}

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

int digit_sum(int x) {
  int res = 0;
  while (x != 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  cin >> N;
  cout << (N % digit_sum(N) == 0 ? "Yes" : "No") << endl;
  return 0;
}

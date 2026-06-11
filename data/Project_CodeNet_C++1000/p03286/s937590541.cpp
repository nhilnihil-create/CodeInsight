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
#include <tuple>
using namespace std;

int main() {
  int N; cin >> N;

  if (N == 0 || N == 1) {
    cout << N << endl;
    return 0;
  }

  stack<int> items;
  while (N != 0) {
    if (N % 2 == 1 || N % 2 == -1) {
      items.push(1);
      --N;
    } else {
      items.push(0);
    }

    N /= -2;
  }

  while (!items.empty()) {
    cout << items.top();
    items.pop();
  }
  cout << endl;

  return 0;
}

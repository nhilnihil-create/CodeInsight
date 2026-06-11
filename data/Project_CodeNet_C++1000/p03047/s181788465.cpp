#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

#define ll long long

int main() {
  int N, K;
  cin >> N >> K;
  cout << max(0, N - K + 1) << endl;
  return 0;
}

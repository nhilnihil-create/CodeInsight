#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B, K; cin >> A >> B >> K;
  set<int> s;
  for (int i = A; i < min(A + K, B); ++i) s.insert(i);
  for (int i = max(A, B - K + 1); i <= B; ++i) s.insert(i);
  for (int v : s) cout << v << endl;
}

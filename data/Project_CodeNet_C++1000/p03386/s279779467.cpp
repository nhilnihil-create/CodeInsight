#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, K;
  cin >> A >> B >> K;

  K = min(K, B - A + 1);

  set<int> rets;
  for (int i = A; i < A + K; ++i) {
    rets.insert(i);
  }
  for (int i = B; i > B - K; --i) {
    rets.insert(i);
  }

  for (set<int>::iterator i = rets.begin(); i != rets.end(); ++i) {
    cout << *i << endl;
  }

  return 0;
}
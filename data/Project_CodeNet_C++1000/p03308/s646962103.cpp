#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &e: A) {
    cin >> e;
  }

  auto m = minmax_element(begin(A),end(A));
  cout << *m.second - *m.first << endl;
  
  return 0;
}

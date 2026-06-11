#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, A, B, P;
  cin >> N >> A >> B;
  vector<int> g(3);
  while (cin >> P) {
    if (P <= A)
      ++g[0];
    else if (P <= B)
      ++g[1];
    else
      ++g[2];
  }
  cout << *min_element(begin(g), end(g)) << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int A, B;
  size_t K;
  cin >> A >> B >> K;

  vector<int> v;
  int upper = min(A, B);
  for (int i = 1; i <= upper; ++i) {
    if (((A % i) == 0) && ((B % i) == 0)) {
      v.push_back(i);
    }
  }
  if (K <= v.size()) {
    cout << v[v.size() - K] << endl;
  }
  return 0;
}

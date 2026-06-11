#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int N, M, ans{};
  cin >> N >> M;
  vector<int> X(M);
  for (int &x : X) cin >> x, ans += x;

  if (N>=M) {
    cout << 0 << endl;
    return 0;
  }
  sort(begin(X),end(X));
  adjacent_difference(begin(X),end(X),begin(X));
  sort(begin(X)+1,end(X));

  cout << accumulate(begin(X)+1,begin(X)+M-N+1,0)
       << endl;
}

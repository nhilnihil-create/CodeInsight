#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  
  vector<int> prices(N+1);
  for (int m = 1; m <= M; ++m) {
    int A;
    cin >> A;
    prices[A] = 1;
  }
  
  int zero = 0;
  for (int i = 1; i < X; ++i) {
    zero += prices[i];
  }
  int n = 0;
  for (int i = X+1; i <= N; ++i) {
    n += prices[i];
  }
  cout << min(zero, n) << endl;
  
  return 0;
}

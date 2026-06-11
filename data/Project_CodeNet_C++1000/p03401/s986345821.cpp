#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  vector<int> A(N+2, 0);
  rep(i, N) {
    cin >> A[i+1];
  }
  
  int sum = 0;
  vector<int> cost(N+2);
  for(int i = 1; i <= N; i++) {
    sum += std::abs(A[i] - A[i-1]);

    int diff1 = std::abs(A[i] - A[i-1]);
    int diff2 = std::abs(A[i+1] - A[i]);
    int diff3 = std::abs(A[i+1] - A[i-1]);

    if (diff1 + diff2 == diff3) {
      cost[i] = 0;
    } else if ((A[i] <= A[i-1] && A[i-1] <= A[i+1]) || (A[i+1] <= A[i-1] && A[i-1] <= A[i])) {
      cost[i] = 2 * std::abs(A[i] - A[i-1]);
    } else {
      cost[i] = 2 * std::abs(A[i+1] - A[i]);
    }
  }
  sum += std::abs(A[N]);

  for(int i = 1; i <= N; i++) {
    cout << sum - cost[i] << endl;
  }

  return 0;
}

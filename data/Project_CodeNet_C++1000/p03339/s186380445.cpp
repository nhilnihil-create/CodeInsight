#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<int> sum_E(N);
  vector<int> sum_W(N);

  int sum = 0;
  for(int i=0; i<N; i++) {
    sum_W[i] = sum;
    if (S[i] == 'W') sum++;
  }
  sum = 0;
  for(int i=N-1; i>=0; i--) {
    sum_E[i] = sum;
    if (S[i] == 'E') sum++;
  }

  int mn = N;
  rep(i, N) {
    if (mn > sum_E[i] + sum_W[i]) mn = sum_E[i] + sum_W[i];
  }

  cout << mn << endl;

  return 0;
}

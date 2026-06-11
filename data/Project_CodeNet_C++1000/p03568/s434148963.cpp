#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int check(vector<int> x, vector<int> comb, int N, int i) {
  if (i == N - 1) {
    int count = 0;
    for (int j = -1; j < 2; ++j) {
      int prod = 1;
      for (int k = 0; k < comb.size(); ++k) {
        prod *= comb[k];
      }
      prod *= x[i] + j;
      if (prod % 2 == 0)
        ++count;
    }
    return count;
  }

  int count = 0;
  for (int j = -1; j < 2; ++j) {
    vector<int> a = comb;
    a.push_back(x[i] + j);
    count += check(x, a, N, i + 1);
  }
  return count;
}

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  vector<int> x(0);
  cout << check(a, x, N, 0) << endl;

  return 0;
}
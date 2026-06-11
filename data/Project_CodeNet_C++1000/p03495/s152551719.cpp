#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int N, K, a;
  cin >> N >> K;
  int A[200000]{};
  while (cin >> a) ++A[a-1];
  sort(rbegin(A),rend(A));
  cout << N - accumulate(begin(A),begin(A)+K,0) << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<long long> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  vector<long long> B(N);
  for (int i = 0; i < N; ++i)
    cin >> B[i];
  vector<long long> C(N);
  for (int i = 0; i < N; ++i)
    cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long long n_c[N];
  for (int i = 0; i < N; ++i) {
    vector<long long>::iterator iter = upper_bound(C.begin(), C.end(), B[i]);
    n_c[i] = distance(iter, C.end());
  }
  for (int i = N - 2; i >= 0; --i) {
    n_c[i] += n_c[i + 1];
  }

  long long ret = 0;
  for (int i = 0; i < N; ++i) {
    vector<long long>::iterator iter = upper_bound(B.begin(), B.end(), A[i]);
    int index = N - distance(iter, B.end());
    if (index != N)
      ret += n_c[index];
  }

  cout << ret << endl;

  return 0;
}
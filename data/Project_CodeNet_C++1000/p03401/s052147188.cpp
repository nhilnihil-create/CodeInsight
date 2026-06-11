#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, s{};
  cin >> N;
  vector<int> A(N + 2);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    s += abs(A[i] - A[i - 1]);
  }
  s += abs(A[N]);
  for (int i = 1; i <= N; ++i) {
    cout << s + abs(A[i + 1] - A[i - 1]) - abs(A[i + 1] - A[i]) -
                abs(A[i] - A[i - 1])
         << endl;
  }
}

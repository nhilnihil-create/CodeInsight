#include <iostream>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  auto f = [](long long x) { return x * x * x; };
  cout << f(N / K) + f(K % 2 ? 0 : (N + K / 2) / K) << endl;
}

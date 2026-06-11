#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N; cin >> N;
  long long res = 0;
  for (long long r = 1; r*r <= N; ++r) {
    if ((N-r) % r == 0 && (N-r)/r > r) res += (N-r)/r;
  }
  cout << res << endl;
}
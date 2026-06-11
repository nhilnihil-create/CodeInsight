#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  vector<bool> prime(55556, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= 55555; ++i) {
    if(!prime[i]) continue;
    for (int j = 2; i * j <= 55555; ++j) {
      prime[i * j] = false;
    }
  }
  int N;
  cin >> N;
  for (int i = 2; i <= 55555 && N; ++i) {
    if (prime[i] && ((i % 5) == 1)) {
      cout << i << " ";
      --N;
    }
  }
  cout << endl;
  return 0;
}
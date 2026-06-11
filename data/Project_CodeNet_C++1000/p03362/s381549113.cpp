#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<bool> is_prime(55556, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= 55555; i++) {
    for (int j = 2 * i; j <= 55555; j += i) {
      is_prime[j] = false;
    }
  }
  int cnt = 0;
  int i = 11;
  while (cnt < N) {
    if (is_prime[i] && i % 5 == 1) {
      cout << i;
      cnt++;
      cout << " \n"[cnt == N];
    }
    i++;
  }
  return 0;
}
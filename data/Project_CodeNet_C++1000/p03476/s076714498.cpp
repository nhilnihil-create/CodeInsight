#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100005;

vector<bool> eratosthenes() {
  vector<bool> is_prime(MAX, true);
  is_prime.at(0) = false; is_prime.at(1) = false;
  for (int i = 2; i < MAX; i++) {
    if (!is_prime.at(i)) continue;
    for (int j = i * 2; j < MAX; j += i) {
      is_prime.at(j) = false;
    }
  }
  return is_prime;
}

vector<int> is_like2017(vector<bool> is_prime) {
  vector<int> is_like2017(MAX, 0);
  for (int i = 0; i < MAX; i++) {
    if (i % 2 == 1 && is_prime.at(i) && is_prime.at((i+1)/2)) {
      is_like2017.at(i) = 1;
    }
  }
  return is_like2017;
}

int main() {
  auto is_prime = eratosthenes();
  auto a = is_like2017(is_prime);
  vector<int> cum_sum(MAX+1, 0);
  for (int i = 0; i < MAX; i++) {
    cum_sum.at(i+1) = cum_sum.at(i) + a.at(i);
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    cout << cum_sum.at(r+1) - cum_sum.at(l) << endl;
  }
}

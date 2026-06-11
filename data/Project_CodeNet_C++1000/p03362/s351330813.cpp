#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
  int N;
  cin >> N;
  vector<ll> vec;
  for (ll i = 6; i <= 55555; i+=5) {
    if (is_prime(i)) {
      vec.push_back(i);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << vec[i] << " ";
  }
  cout << "\n";
  return 0;
}
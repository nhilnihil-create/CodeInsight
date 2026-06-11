#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

vector<bool> sieve(int N) {
  vector<bool> is_prime(N + 1);
  for (int i = 0; i < N + 1; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = 2; i * j <= N; ++j) is_prime[i * j] = false;
    }
  }
  return is_prime;
}

int main() {
  ll Q;
  cin >> Q;
  int l, r, max_num = 0;
  vector<pair<ll, ll>> query;
  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    max_num = max(max_num, r);
    query.push_back({l, r});
  }
  vector<bool> is_prime = sieve(max_num);
  vector<ll> prime_cnt(max_num + 1, 0);
  for (int i = 2; i < is_prime.size(); i++) {
    if (is_prime[i] && is_prime[(i + 1) / 2]) prime_cnt[i]++;
    prime_cnt[i] += prime_cnt[i - 1];
  }
  for (auto q : query) {
    l = q.first;
    r = q.second;
    ll cnt = prime_cnt[r] - prime_cnt[l - 1];
    cout << cnt << endl;
  }
  return 0;
}
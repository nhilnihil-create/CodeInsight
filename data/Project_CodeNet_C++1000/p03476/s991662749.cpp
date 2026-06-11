#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  // エラトステネスの篩
  int MAX = 101010;
  vector<int> is_prime(MAX, 1);
  is_prime[0] = 0, is_prime[1] = 0;
  for (int i = 2; i < MAX; ++i) {
    // すでに素数でないとされているので飛ばす
    if (!is_prime[i]) continue;
    // iの2倍3倍4倍はiで割り切れる
    for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
  }

  // 2017-like 数かどうか
  // Nも(N+1)/2も素数を満たす奇数Nかどうかの配列
  vector<int> a(MAX, 0);
  for (int i = 0; i < MAX; ++i) {
    if (i % 2 == 0) continue;
    if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
  }

  // 上の配列を利用して、累積和する
  vector<int> s(MAX+1, 0);
  for (int i = 0; i < MAX; ++i) s[i+1] = s[i] + a[i];

  // クエリ処理
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int l, r;
    cin >> l >> r;
    ++r;

    cout << s[r] - s[l] << endl;
  }
  
  return 0;
}
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

bool isprime(int v) {
  if (v == 1) return false;
  for (int i = 2; 1ll * i * i <= v; ++i)
    if (v % i == 0) return false;

  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> v[5];
  rep(i, 55556) if (isprime(i)) v[i % 5].push_back(i);

  rep(i, n) cout << v[1][i] << (i == n - 1 ? "\n" : " ");
  return 0;
}
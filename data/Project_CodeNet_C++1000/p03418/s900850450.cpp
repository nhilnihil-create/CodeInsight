#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ll n, k, o = 0;
  cin >> n >> k;
  for(int i = k + 1; i <= n; i++)
    o += n / i * (i - k) + max(0LL, n % i - k + 1);
  cout << (k ? o : n * n) << '\n';
}
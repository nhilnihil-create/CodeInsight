#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  ll ans = 0;
  if (B - A <= 2) ans = K + 1;
  else ans = A + ((K - (A-1)) / 2) * (B - A) + (K - (A-1)) % 2;
  cout << ans << endl;
}
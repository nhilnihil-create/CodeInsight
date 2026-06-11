#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll i = 1; i * i < N; i ++) {
    if (N % i == 0) {
      ll kj = N / i;
      kj --;
      if (N / kj == N % kj) ans += kj;
      kj = i - 1;
      if (kj != 0 && N / kj == N % kj) ans += kj;
    }
  }
  cout << ans << endl;
}

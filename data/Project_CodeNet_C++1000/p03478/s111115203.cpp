#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dig(ll x) {
  ll ans = 0;
  while(x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll sum = 0;
  for(ll i = 1; i <= N; i++) {
    ll C = dig(i);
    if(A <= C && C <= B) {
      sum += i;
    }
  }
  cout << sum << endl;
}
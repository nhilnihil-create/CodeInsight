#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector<ll> B(N);
  rep(i,N){
    ll x;
    cin >> x;
    B[i] = x - i - 1;
  }

  sort(B.begin(), B.end());

  ll base =  B[N/2];

  //rep(i,N) cout << B[i] << endl;

  ll ans = 0;

  rep(i, N) ans += abs(B[i]-base);

  cout << ans << endl;



}

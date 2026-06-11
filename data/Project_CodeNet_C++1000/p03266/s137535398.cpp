#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  if (K % 2 != 0) {
    cout << setprecision(16) << pow(N / K, 3) << endl;
  }
  else {
    ll temp = N / K;
    ll ans = pow(temp, 3);
    ans += pow((N / (K / 2)) - temp, 3);
    cout << setprecision(16) << ans << endl;
  }
}

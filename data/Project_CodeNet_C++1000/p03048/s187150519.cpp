#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;


int main()
{
  ll R, G, B, N;
  cin >> R >> G >> B >> N;
  ll ans = 0;
  for (ll i = 0; i * R <= N; ++i) {
    ll red = i * R;
    for (ll j = 0; j * G <= N - red; ++j) {
      ll green = j * G;
      if ((N - red - green) % B == 0) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;
}

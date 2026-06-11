#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  std::cout << std::fixed << std::setprecision(10);

  ll N;
  scanf("%lld", &N);

  long double ans = 0;

  for (ll i = 0; i < N; i++) {
    string a, b;
    cin >> a >> b;

    if (b == "JPY") {
      ans += stoll(a);
    }
    if (b == "BTC") {
      ans += stold(a) * 380000LL;
    }
  }
  cout << ans << endl;
}

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

ll f[105];

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> goal(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    goal[i] = v;
  }

  ll count = 0;
  for (;;) {
    ll start = -1;
    ll end = -1;
    for (ll i = 0; i < N; i++) {
      if (start == -1) {
        if (f[i] < goal[i]) {
          start = i;
        }
      } else {
        if (f[i] >= goal[i]) {
          end = i - 1;
          break;
        }
      }
    }
    if (start == -1) {
      break;
    }
    if (end == -1) {
      end = N - 1;
    }
    for (ll i = start; i <= end; i++) {
      f[i]++;
    }
    count++;
  }
  cout << count << endl;
}

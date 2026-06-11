#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> a(N);
  vector<ll> b(N);
  ll a_sum = 0, b_sum = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> a.at(i);
    a_sum += a.at(i);
  }
  for (ll i = 0; i < N; ++i) {
    cin >> b.at(i);
    b_sum += b.at(i);
  }
  ll num = b_sum - a_sum;
  ll dif = 0;
  for (ll i = 0; i < N; ++i) {
    if (a.at(i) < b.at(i)) {
      dif += (1 + b.at(i) - a.at(i)) / 2;
    }
  }
  if (num >= dif) {
    cout << "Yes" << "\n";
  }
  else {
    cout << "No" << "\n";
  }
}

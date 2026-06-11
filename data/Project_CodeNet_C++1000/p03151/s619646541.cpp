#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  ll a_sum = 0, b_sum = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
    a_sum += A.at(i);
  }
  for (ll i = 0; i < N; ++i) {
    ll b;
    cin >> b;
    B.at(i) = b;
    b_sum += b;
  }
  if (a_sum < b_sum) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  vector<bool> chage(N, false);
  ll chage_num = 0;
  for (ll i = 0; i < N; ++i) {
    if (A.at(i) < B.at(i)) {
      chage.at(i) = true;
      chage_num += B.at(i) - A.at(i);
      ans += 1;
    }
  }
  vector<ll> can_chage;
  for (ll i = 0; i < N; ++i) {
    if (chage.at(i)) {
      continue;
    }
    can_chage.push_back(A.at(i) - B.at(i));
  }
  sort(can_chage.begin(), can_chage.end());
  reverse(can_chage.begin(), can_chage.end());
  ll temp = 0;
  for (ll i = 0; i < can_chage.size(); ++i) {
    if (temp >= chage_num) {
      break;
    }
    temp += can_chage.at(i);
    ans += 1;
  }
  cout << ans << endl;
}

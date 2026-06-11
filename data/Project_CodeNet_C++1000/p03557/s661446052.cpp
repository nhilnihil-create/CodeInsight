#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll sum2[1000005];

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  vector<ll> list1(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list1[i] = v;
  }

  vector<ll> list2(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list2[i] = v;
  }

  vector<ll> list3(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list3[i] = v;
  }

  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());
  sort(list3.begin(), list3.end());

  // sum2;

  ll sum = 0;

  for (ll i2 = 0; i2 < list2.size(); i2++) {
    ll v2 = list2[i2];
    auto ite = upper_bound(list3.begin(), list3.end(), v2);
    ll s = list3.end() - ite;
    sum2[i2] = s;
    // cout << "s:" << s << endl;
  }
  for (ll i = N - 2; i >= 0; i--) {
    sum2[i] += sum2[i + 1];
  }

  for (ll i1 = 0; i1 < list1.size(); i1++) {
    ll v = list1[i1];

    auto ite = upper_bound(list2.begin(), list2.end(), v);
    ll index = ite - list2.begin();  // 先頭までの距離
    ll plus = sum2[index];
    sum += plus;

    // cout << "index:" << index << endl;
    // cout << "plus:" << plus << endl;
  }
  cout << sum << endl;
}

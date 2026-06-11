#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  ll N, M, X, Y;
  scanf("%lld %lld %lld %lld", &N, &M, &X, &Y);

  vector<ll> x_list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    x_list.emplace_back(v);
  }

  vector<ll> y_list;
  for (ll i = 0; i < M; i++) {
    ll v;
    scanf("%lld", &v);
    y_list.emplace_back(v);
  }

  sort(x_list.begin(), x_list.end());
  sort(y_list.begin(), y_list.end());

  // cout << "x_list[N - 1]:" << (x_list[N - 1]) << endl;
  // cout << (y_list[0]) << endl;

  if (X < y_list[0] && x_list[N - 1] < Y && x_list[N - 1] < y_list[0]) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}

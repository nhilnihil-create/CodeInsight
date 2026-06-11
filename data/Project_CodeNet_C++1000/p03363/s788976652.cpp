#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  vector<ll> sum(N); // 累積和
  sum[0] = A[0];
  for (int i=1; i<N; i++) sum[i] = sum[i-1]+A[i];
  map<ll, ll> dict; // sumに登場する数字と登場回数
  for (int i=0; i<N; i++) {
    if (dict.count(sum[i])) dict[sum[i]]++;
    else dict[sum[i]] = 1;
  }
  ll res = 0;
  for (auto p: dict) {
    auto key = p.first;
    auto value = p.second;
    res += value*(value-1)/2;
    if (key==0) res += value;
  }
  cout << res << endl;
  return 0;
}
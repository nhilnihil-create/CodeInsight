#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int N;
  string S;
  cin >> N >> S;
  map<char, ll> dict; // 各文字の出現回数
  for (int i=0; i<N; i++) {
    if (dict.count(S[i])) dict[S[i]]++;
    else dict[S[i]] = 1;
  }
  ll res = 1;
  for (auto p: dict) {
    auto value = p.second;
    res *= value+1;
    res %= MOD;
  }
  if (res==0) cout << 1000000006 << endl;
  else cout << res-1 << endl;
}
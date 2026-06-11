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
  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> V;
  for (int i=0; i<N; i++) {
    int a;
    cin >> a;
    V.push_back({a, 1});
  }
  for (int i=0; i<M; i++) {
    int b, c;
    cin >> b >> c;
    V.push_back({c, b});
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  ll num = 0, res = 0;
  for (auto p: V) {
    if (num+p.second<=N) {
      res += p.first*p.second;
      num += p.second;
    }
    else {
      res += p.first*(N-num);
      num = N;
      break;
    }
  }
  cout << res << endl;
  return 0;
}
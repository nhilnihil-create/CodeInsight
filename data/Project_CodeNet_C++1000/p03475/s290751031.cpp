#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
int main() {
  ll N;
  cin >> N;
  vector<ll> C(N), S(N), F(N);
  vector<vector<ll>> dist_time(N);
  ll sum_s = 0;
  for (int i = 0; i < N - 1; i++) {
    cin >> C[i] >> S[i] >> F[i];
    sum_s += S[i] + C[i];
  }
  for (int i = 0; i < N - 1; i++) {
    ll t = S[i] + C[i];
    for (int j = i + 1; j < N - 1; j++) {
      ll start = (t % F[j] == 0) ? t : F[j] * (t / F[j] + 1);
      start = max(S[j], start);
      // cout << i + 1 << "," << j + 1 << "," << start << endl;
      t = start + C[j];
    }
    cout << t << endl;
  }
  cout << 0 << endl;
  return 0;
}
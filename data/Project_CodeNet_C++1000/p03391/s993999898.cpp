#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
ll INF = Mod * 100LL;
int main() {
  int N;
  cin >> N;
  ll ans = 0;
  ll sum = 0;
  ll mini = INF;
  bool all_same = true;
  for (int i = 0; i < N; i++) {
    ll A,B;
    cin >> A >> B;
    sum += A;
    if (A != B) all_same = false;
    if (A > B) {
      mini = min(mini,B);
    }
  }
  if (all_same) {
    cout << 0 << endl;
    return 0;
  }
  cout << sum - mini << endl;
  return 0;
}
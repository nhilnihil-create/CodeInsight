#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n, k;
  cin >> n >> k;
  vector<P> vec;
  REP(i, n) {
    int t, d;
    cin >> t >> d;
    t--;
    vec.push_back(P(d, t));
  }
  sort(ALL(vec));
  reverse(ALL(vec));
  set<int> set;
  stack<int> stack;
  ll sum = 0;
  REP(i, k) {
    if (set.count(vec[i].second)) {
      stack.push(vec[i].first);
    } else {
      set.insert(vec[i].second);
    }
    sum += vec[i].first;
  }
  ll ans = sum + set.size() * set.size();
  for (int i = k; i < n; ++i) {
    if (set.count(vec[i].second)) continue;
    if (stack.empty()) break;
    sum -= stack.top();
    stack.pop();
    set.insert(vec[i].second);
    sum += vec[i].first;
    ll res = sum + set.size() * set.size();
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}
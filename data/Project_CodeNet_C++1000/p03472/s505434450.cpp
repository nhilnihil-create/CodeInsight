#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n, h;
  cin >> n >> h;
  priority_queue<int> a_queue;
  priority_queue<int> b_queue;
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    a_queue.push(a);
    b_queue.push(b);
  }
  int ans = 0;
  while (h > 0 && !b_queue.empty()) {
    if (b_queue.top() > a_queue.top()) {
      h -= b_queue.top();
      b_queue.pop();
      ans++;
    } else {
      break;
    }
  }
  if (h > 0) {
    ans += h / a_queue.top();
    ans += (h % a_queue.top() != 0);
  }
  cout << ans << endl;
}
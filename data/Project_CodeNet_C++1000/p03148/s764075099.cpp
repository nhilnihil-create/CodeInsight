#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, int> P;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  ll n, k;
  cin >> n >> k;

  priority_queue<P> p;
  for (int i = 0; i < n; i++) {
    ll t, d;
    cin >> t >> d;
    p.push(make_pair(d, t));
  }

  vector<ll> ma(n + 1);                           // 種類数がiの時のおいしさ最大
  vector<int> neta(n + 1);                        // ネタiをどれだけ選んでいるか
  priority_queue<P, vector<P>, greater<P>> have;  // 手持ちのやつ

  // まず大きい順にK個取り出す
  ll oishi = 0, count = 0;
  for (int i = 0; i < k; i++) {
    auto now = p.top();
    p.pop();
    oishi += now.first;
    if (neta[now.second] == 0) count++;
    neta[now.second]++;
    have.push(now);
  }

  ll ans = oishi + count * count;  // 現時点で最高
  while (!p.empty() && !have.empty()) {
    while (neta[p.top().second] != 0 && !p.empty()) p.pop();          // 初めてのネタが来るまで
    while (neta[have.top().second] < 2 && !have.empty()) have.pop();  // 2つ以上だぶってるネタが来るまで
    if (p.empty() || have.empty()) continue;

    neta[p.top().second]++;
    neta[have.top().second]--;
    oishi = oishi - have.top().first + p.top().first;
    count++;
    p.pop();
    have.pop();

    ans = max(ans, oishi + count * count);
  }

  cout << ans << endl;
}

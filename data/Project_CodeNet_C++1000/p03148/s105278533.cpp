#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int, int>;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n, k; cin >> n >> k;

  unordered_map<int, vl> G;
  int t, d;

  rep(i,n) {
    cin >> t >> d;
    G[t].push_back(d);
  }

  for (auto &p : G) sort(ALL(p.second), greater<ll>());

  priority_queue<P> next;  // P(d,t)
  for (auto &p : G) next.push(P(p.second[0], p.first));

  unordered_map<int, int> eat;  // <t, number>
  ll satisfaction = 0;

  rep(i,k) {
    tie(d,t) = next.top(); next.pop();
    ++eat[t];
    satisfaction += d;

    if (eat[t] < G[t].size()) next.push(P(G[t][eat[t]], t));
  }

  int variety = eat.size();
  satisfaction += (ll)pow(variety, 2);

  unordered_map<int, ll> bonus;
  bonus[variety] = 0;

  priority_queue<P, vector<P>, greater<P>> twice;  // P(d,t)
  int num;

  for (auto p : eat) {
    tie(t,num) = p;
    if (num != 1) twice.push(P(G[t][num-1], t));
  }

  int nt, nd;

  while (!next.empty() && !twice.empty()) {
    tie(nd,nt) = next.top(); next.pop();

    if (!eat.count(nt)) {
      tie(d,t) = twice.top(); twice.pop();
      bonus[variety+1] = bonus[variety] + (nd - d) + (variety*2 + 1);
      ++variety;
      --eat[t];

      if (eat[t] != 1) twice.push(P(G[t][eat[t]-1], t));
    }
  }

  ll increase = 0;
  for (auto p : bonus) increase = max(increase, p.second);

  ll ans = satisfaction + increase;
  cout << ans << endl;
  return 0;
}

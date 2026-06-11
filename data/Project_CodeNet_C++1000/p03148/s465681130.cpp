#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P = pair<int, int>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<P> s(n);
  rep(i, n) cin >> s[i].second >> s[i].first;
  sort(s.rbegin(), s.rend());
  ll sum = 0;
  set<int> st;
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i, k) {
    sum += s[i].first;
    if (st.find(s[i].second) == st.end())
      st.insert(s[i].second);
    else
      que.push(s[i].first);
  }
  ll var = st.size();
  ll ans = sum+var*var;
  for (int i = k; i < n && !que.empty(); i++) {
    if (st.find(s[i].second) != st.end())
      continue;
    int num;
    num = que.top();
    que.pop();
    sum += s[i].first-num;
    st.insert(s[i].second);
    var++;
    chmax(ans, sum+var*var);
  }
  cout << ans << endl;
  return 0;
}
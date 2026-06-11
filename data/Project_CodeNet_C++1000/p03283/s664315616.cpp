#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> a(N, vector<int>(N, 0));
  rep(i, M)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    a.at(l).at(r)++;
  }
  vector<int> p(Q), q(Q);
  rep(i, Q)
  {
    cin >> p.at(i) >> q.at(i);
    p.at(i)--;
    q.at(i)--;
  }
  vector<vector<int>> s(N + 1, vector<int>(N + 1, 0));
  rep(i, N)
  {
    rep(j, N)
    {
      s.at(i + 1).at(j + 1) = s.at(i + 1).at(j) + s.at(i).at(j + 1) - s.at(i).at(j) + a.at(i).at(j);
    }
  }
  vector<int> ans(Q);
  rep(i, Q)
  {
    ans.at(i) = s.at(q.at(i) + 1).at(q.at(i) + 1) - s.at(q.at(i) + 1).at(p.at(i)) - s.at(p.at(i)).at(q.at(i) + 1) + s.at(p.at(i)).at(p.at(i));
  }
  rep(i, Q) cout << ans.at(i) << endl;
}
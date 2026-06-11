#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 60);

int main()
{
  int64_t A, B, Q, x;
  cin >> A >> B >> Q;
  vector<int64_t> S(A), T(B);
  for (int i = 0; i < A; i++)
  {
    cin >> S.at(i);
  }
  for (int i = 0; i < B; i++)
  {
    cin >> T.at(i);
  }
  queue<int64_t> ans;
  for (int i = 0; i < Q; i++)
  {
    cin >> x;
    int64_t sl, tl, sr, tr, d1 = INF, d2 = INF, d3 = INF, d4 = INF;
    auto it_sr = lower_bound(S.begin(), S.end(), x);
    sr = it_sr == S.end() ? -1 : *it_sr;
    sl = it_sr == S.begin() ? -1 : *(it_sr - 1);
    auto it_tr = lower_bound(T.begin(), T.end(), x);
    tr = it_tr == T.end() ? -1 : *it_tr;
    tl = it_tr == T.begin() ? -1 : *(it_tr - 1);
    if (sl != -1 && tl != -1)
      d1 = max(x - sl, x - tl);
    if (sr != -1 && tr != -1)
      d2 = max(sr - x, tr - x);
    if (tl != -1 && sr != -1)
      d3 = (x - tl) + (sr - x) + min((x - tl), (sr - x));
    if (sl != -1 && tr != -1)
      d4 = (x - sl) + (tr - x) + min((x - sl), (tr - x));
    ans.push(min(min(d1, d2), min(d3, d4)));
  }
  while (!ans.empty())
  {
    cout << ans.front() << endl;
    ans.pop();
  }
}
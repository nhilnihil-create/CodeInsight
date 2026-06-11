#include <bits/stdc++.h>
using namespace std;
int64_t MAXN = 200000;
int64_t N, cnt = 0;
string S;
vector<int64_t> W(MAXN, 0), B(MAXN, 0); // 累積和を取る

int64_t dfs(int64_t idx, int64_t cnt, bool rW)
{
  if (idx < 0)
    return cnt;
  if (rW) // 右が白 => iも白でなければNG
  {
    if (S.at(idx) == '#')
      return dfs(idx - 1, cnt + 1, true); // 黒ならばひっくり返す。rW = trueのまま。
    else
      return dfs(idx - 1, cnt, true); // 右が白、idxも白 -> そのまま。
  }
  else // iが白ならば、黒に変える or そのまま
  {
    if (S.at(idx) == '.')
    {
      int64_t ret1, ret2;
      ret1 = B.at(idx) + cnt;              // idx以前の黒を全てひっくり返す。
      ret2 = dfs(idx - 1, cnt + 1, false); // idxの白を黒にひっくり返す。
      return min(ret1, ret2);
    }
    else // 右が黒 => iも黒ならばそのまま
    {
      return dfs(idx - 1, cnt, false);
    }
  }
}

int main()
{
  cin >> N >> S;
  for (int i = 0; i < N; i++)
  {
    if (i != 0)
    {
      W.at(i) += W.at(i - 1);
      B.at(i) += B.at(i - 1);
    }
    S.at(i) == '.' ? W.at(i)++ : B.at(i)++;
  }
  cout << dfs(N - 1, 0, false) << endl;
}
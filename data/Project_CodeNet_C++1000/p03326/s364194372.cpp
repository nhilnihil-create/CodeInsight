 #include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M; cin >> N >> M;
  vector<vector<int64_t>> xyzs(N, vector<int64_t>(3)); for (int i = 0; i < N; ++i) cin >> xyzs[i][0] >> xyzs[i][1] >> xyzs[i][2];
  vector<int64_t> ss(N);
  auto ans = 0LL;
  for (int i = 0; i < 8; ++i)
    {for (int j = 0; j < N; ++j)
      {auto s = 0LL; for (int k = 0; k < 3; ++k) s += (i >> k & 1 ? -1 : 1) * xyzs[j][k];
      ss[j] = s;}
    auto t = 0LL; sort(ss.rbegin(), ss.rend()); for (int j = 0; j < M; ++j) t += ss[j];
    ans = max(ans, t);}
  cout << ans << endl;}
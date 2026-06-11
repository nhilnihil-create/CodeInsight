#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, a, n, x, ans = 0;
  cin >> N >> M;
  vector<int64_t> S(N + 1, 0); // S[r] - S[l] : l~rの和
  map<int64_t, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    S.at(i + 1) = (S.at(i) + (a % M)) % M;
    mp[S.at(i + 1)]++;
    if (S.at(i + 1) == 0)
      ans++;
  }
  for (auto p : mp)
  {
    tie(n, x) = p;
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;
}
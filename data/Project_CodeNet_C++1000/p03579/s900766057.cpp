#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
#define int long long int
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
int color[200005] = {};
vector<int> e[200005];
bool is_bipartiy(int u, int col)
{
  if (color[u] != -1)
    return col == color[u];
  color[u] = col;
  for (auto s : e[u])
  {
    if (!is_bipartiy(s, 1 - col))
      return false;
  }
  return true;
}
void solve(long long N, long long M, std::vector<long long> A,
           std::vector<long long> B)
{
  rep(i, N) color[i] = -1;
  rep(i, M) e[A[i] - 1].push_back(B[i] - 1), e[B[i] - 1].push_back(A[i] - 1);
  if (!is_bipartiy(0, 0))
  {
    cout << N * (N - 1) / 2 - M << endl;
    return;
  }

  lli blue = 0;
  rep(i, N)
  {
    if (color[i])
      blue++;
  }
  cout << blue * (N - blue) - M << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> A(M);
  std::vector<long long> B(M);
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, M, std::move(A), std::move(B));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}

#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;

void solve()
{
  int N;
  cin >> N;

  vector<int> A(N);

  REP0(i, N)
  {
    cin >> A[i];
  }

  vector<int> L(N), R(N);
  L[0] = abs(A[0]);
  R[N - 1] = abs(A[N - 1]);

  REP1(i, N - 1)
  {
    L[i] = L[i - 1] + abs(A[i - 1] - A[i]);
    R[N - i - 1] = R[N - i] + abs(A[N - i - 1] - A[N - i]);
  }

  REP0(i, N)
  {
    if (i == 0)
    {
      cout << abs(A[i + 1]) + R[i + 1] << endl;
      continue;
    }
    if (i == N - 1)
    {
      cout << abs(A[i - 1]) + L[i - 1] << endl;
      continue;
    }

    cout << L[i - 1] + abs(A[i - 1] - A[i + 1]) + R[i + 1] << endl;
  }
}

int main(int argc, char const *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(10);
  solve();
  return 0;
}
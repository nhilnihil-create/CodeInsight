#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
int64_t pow3[100010];
bool dp[100010];

void init()
{
  pow3[0] = 1;
  for (int i = 1; i < 100010; i++)
  {
    pow3[i] = 3 * pow3[i - 1] % MOD;
  }
}

int64_t POW3(int x)
{
  if (x < 0)
    return 0;
  else
    return pow3[x];
}

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  vector<int64_t> A(N + 1, 0), B(N + 1, 0), C(N + 1, 0), Q(N + 1, 0); // V[r+1] - V[l]
  for (int i = 0; i < N; i++)
  {
    if (S[i] == 'A')
      A[i + 1]++;
    if (S[i] == 'B')
      B[i + 1]++;
    if (S[i] == 'C')
      C[i + 1]++;
    if (S[i] == '?')
      Q[i + 1]++;
    A[i + 1] += A[i];
    B[i + 1] += B[i];
    C[i + 1] += C[i];
    Q[i + 1] += Q[i];
  }
  init();
  int64_t ans = 0;
  for (int i = 1; i < N - 1; i++)
  {
    if (S[i] == 'A' || S[i] == 'C')
      continue;
    int64_t la = A[i], lq = Q[i], rc = (C[N] - C[i + 1]), rq = (Q[N] - Q[i + 1]);

    int64_t l = ((la * POW3(lq)) % MOD + (lq * POW3(lq - 1)) % MOD) % MOD;
    int64_t r = ((rc * POW3(rq)) % MOD + (rq * POW3(rq - 1)) % MOD) % MOD;
    (ans += (l * r)) %= MOD;
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N)
  {
    cin >> S[i];
  }
  int ans = 0;
  rep(A, N)
  {
    bool is_ok = true;
    rep(i, N) rep(j, N)
    {
      if (i == j)
        continue;
      if (S[(i + A) % N][j] != S[(j + A) % N][i])
      {
        is_ok = false;
        goto endloop;
      }
    }
  endloop:

    if (is_ok)
      ans += N;
  }
  cout << ans << endl;
  return 0;
}
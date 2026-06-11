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
  string A, B, C;
  cin >> N >> A >> B >> C;
  int ans = 0;
  rep(i, N)
  {
    if (A[i] != B[i] && B[i] != C[i] && C[i] != A[i])
      ans += 2;
    else if (A[i] == B[i] && B[i] == C[i])
      continue;
    else
      ans++;
  }
  cout << ans << endl;
  return 0;
}
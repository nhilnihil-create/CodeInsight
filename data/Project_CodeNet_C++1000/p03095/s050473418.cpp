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
  string S;
  cin >> N >> S;
  vector<int> alphabet_count(26, 0);
  long long mod = 1e9 + 7;
  long long ans = 0;
  rep(i, S.size())
  {
    long long temp = 1;
    rep(j, 26)
    {
      int c = S[i] - 'a';
      if (alphabet_count[j] == 0 || c == j)
        continue;
      temp *= alphabet_count[j] + 1;
      temp %= mod;
    }
    ans += temp;
    ans %= mod;
    alphabet_count[S[i] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}
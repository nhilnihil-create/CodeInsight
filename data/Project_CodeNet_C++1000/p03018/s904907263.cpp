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

long long count(string S)
{
  long long N = S.size();
  long long A_count = 0;
  long long rst = 0;
  rep(i, N)
  {
    if (S[i] == 'A')
      A_count++;
    else
      rst += A_count;
  }

  return rst;
}

int main()
{
  string s;
  cin >> s;
  long long N = s.size();
  rep(i, N - 1)
  {
    if (s.substr(i, 2) == "BC")
    {
      s[i] = 'D';
      s[i + 1] = 'X';
    }
  }
  string SS;
  rep(i, s.size())
  {
    if (s[i] != 'X')
      SS.push_back(s[i]);
  }

  long long ans = 0;
  rep(l, SS.size())
  {
    if (SS[l] == 'A' || SS[l] == 'D')
    {
      long long r = l;
      while (r + 1 < SS.size())
      {
        if (SS[r + 1] == 'A' || SS[r + 1] == 'D')
          r++;
        else
          break;
      }
      ans += count(SS.substr(l, r - l + 1));
      l = r;
    }
  }
  cout << ans << endl;
  return 0;
}
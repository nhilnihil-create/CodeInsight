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
  string s;
  cin >> s;
  int head = 0, tail = s.size() - 1;
  int ans = 0;
  while (tail - head > 0)
  {
    if (s[head] == s[tail])
    {
      head++;
      tail--;
    }
    else if (s[head] == 'x')
    {
      head++;
      ans++;
    }
    else if (s[tail] == 'x')
    {
      tail--;
      ans++;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}
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
  int ans = 0;
  vector<int> count(3, 0); // BXXA, Bxx, xxA
  rep(i, N)
  {
    string s;
    cin >> s;
    rep(j, s.size() - 1)
    {
      if (s[j] == 'A' && s[j + 1] == 'B')
        ans++;
    }

    if (s.front() == 'B' && s.back() == 'A')
      count[0]++;
    else if (s.front() == 'B')
      count[1]++;
    else if (s.back() == 'A')
      count[2]++;
  }

  ans += count[0] + min(count[1], count[2]);
  if (count[0] > 0 && count[1] + count[2] == 0)
    ans--;

  cout << ans << endl;
  return 0;
}
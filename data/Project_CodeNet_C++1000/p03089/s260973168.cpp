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
  vector<int> b(N);
  rep(i, N)
  {
    cin >> b[i];
    b[i]--;
  }

  REVERSE(b);
  vector<int> ans;
  rep(i, N)
  {
    rep(j, b.size())
    {
      int ri = b.size() - j - 1;
      if (b[j] == (ri))
      {
        b.erase(b.begin() + j);
        ans.push_back(ri + 1);
        break;
      }
    }

    if (ans.size() != i + 1)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  REVERSE(ans);
  rep(i, N)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
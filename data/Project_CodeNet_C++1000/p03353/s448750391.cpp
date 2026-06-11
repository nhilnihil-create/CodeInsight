#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T>
void chmin(T &a, T b) { a = min(a, b); }
template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int k, n = 0;
  cin >> s >> k;
  n = s.size();

  set<string> dset;
  rep(i, 0, n)
  {
    string x = string() + s[i];
    dset.insert(x);
    rep(j, i + 1, i + k)
    {
      if (j >= n)
        break;
      x += s[j];
      dset.insert(x);
    }
  }

  int i = 0;
  for (auto d : dset)
  {
    i++;
    if (i == k)
    {
      cout << d << endl;
      return 0;
    }
  }
}

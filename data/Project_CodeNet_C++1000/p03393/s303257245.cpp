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
  string S;
  cin >> S;
  vector<int> alphabet(26);
  rep(i, S.size())
  {
    alphabet[S[i] - 'a']++;
  }
  int ans = 0;
  rep(i, 26)
  {
    if (alphabet[i] == 0)
    {
      char c = i + 'a';
      cout << S + c << endl;
      return 0;
    }
  }
  int N = S.size();
  rep(i, N)
  {
    int c = S.back() - 'a';
    alphabet[c]--;
    S.pop_back();
    for (int j = c + 1; j < 26; j++)
    {
      if (alphabet[j] == 0)
      {
        c = j + 'a';
        S += c;
        cout << S << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
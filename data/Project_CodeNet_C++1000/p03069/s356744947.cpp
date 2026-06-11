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
  vector<int> white_count(N + 1), black_count(N + 1);
  rep(i, N)
  {
    if(S[i] == '#')
      black_count[i + 1]++;
    
    if(S[N - i - 1] == '.')
      white_count[i + 1]++;
  }

  rep(i, N)
  {
    black_count[i + 1] += black_count[i];
    white_count[i + 1] += white_count[i];
  }
  REVERSE(white_count);
  int ans = INT32_MAX;
  rep(i, N + 1)
  {
    //cout << black_count[i] << ", " << white_count[i] << endl;
    int score = black_count[i] + white_count[i];
    ans = min(ans, score);
  }

  cout << ans << endl;
  return 0;
}